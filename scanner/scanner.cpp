#include "scanner.h"
#include "keyword.h"
#include "tokentype.h"
#include <fstream>
#include <cctype>
using namespace std;
void Scanner::skipblank()
{
    while(iter!=code.cend() && *iter!=EOF)
    {
        if(*iter=='\n')
        {
            iter++;
            line++;
        }
        else if(isblank(*iter))
        {
            iter++;
        }
        else
        {
            break;
        }
    }
}

void Scanner::deal_Begin( string &name, Token_Type &type)
{
    if( isdigit(*iter))
        proc = Process::in_integer;
    else if( isalpha(*iter) || *iter=='_')
        proc = Process::in_id;
    else if(*iter==',' || *iter==';' || *iter=='{' || *iter=='}'
            || *iter=='[' || *iter==']' || *iter=='(' || *iter==')'
            || *iter=='#' || *iter=='.' || *iter=='"' || *iter=='\'')
        proc = Process::in_delimiter;
    else
        proc = Process::in_operator;
}

void Scanner::deal_KeyWord( string &name, Token_Type &type)
{
    type = Token_Type::KEYWORD;
    proc = Process::end;
}

void Scanner::deal_ID( string &name, Token_Type &type)
{
    if( isalnum(*iter))
    {
        name+=*iter;
        iter++;
    }
    else if(keywords.find(name) != keywords.end())
    {
        proc = Process::in_keyword;
    }
    else
    {
        type = Token_Type::ID;
        proc = Process::end;
    }
}

void Scanner::deal_Integer( string &name, Token_Type &type)
{
    if( isdigit(*iter))
    {
        name+=*iter;
        iter++;
    }
    else if(*iter == '.')
    {
        name+=*iter;
        iter++;
        proc = Process::in_float;
    }
    else
    {
        type = Token_Type::INT;
        proc = Process::end;
    }
}

void Scanner::deal_Float( string &name, Token_Type &type)
{
    if( isdigit(*iter))
    {
        name+=*iter;
        iter++;
    }
    else
    {
        type = Token_Type::FLOAT;
        proc = Process::end;
    }
}

void Scanner::deal_Operator( string &name, Token_Type &type)
{
    if(*iter=='*' || *iter=='/' || *iter=='%' || *iter=='^' || *iter=='~')
    {
        name+=*iter;
        iter++;
        type = Token_Type::OPERATOR;
        proc = Process::end;
    }
    else if(*iter=='!' || *iter=='=' || *iter=='&' || *iter=='|' || *iter=='<' || *iter=='>' || *iter=='+' || *iter=='-')
    {
        name+=*iter;
        const char lastOp = *iter;
        iter++;
        if(iter!=code.cend())
        {
            if(lastOp=='!' && *iter=='=')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='=' && *iter=='=')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='&' && *iter=='&')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='|' && *iter=='|')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='<' && *iter=='=')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='>' && *iter=='=')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='+' && *iter=='+')
            {
                name+=*iter;
                *iter++;
            }
            else if(lastOp=='-' && *iter=='-')
            {
                name+=*iter;
                *iter++;
            }
            type = Token_Type::OPERATOR;
            proc = Process::end;
        }
    }
    else
    {
        type = Token_Type::OTHER;
        proc = Process::end;
    }
}

void Scanner::deal_Delimiter( string &name, Token_Type &type)
{
    name+=*iter;
    iter++;
    type = Token_Type::DELIMITER;
    proc = Process::end;
}

Token Scanner::deal_End(const  string &name, const Token_Type &type)
{
    return Token(name,type,line);
}

void Scanner::deal_Char( string &name, Token_Type &type)
{
    if(*iter=='\'')
    {
        type = Token_Type::CHAR;
        proc = Process::end;
    }
    name+=*iter;
    iter++;
}

bool Scanner::openfile(const  string &file_name)
{
     ifstream in(file_name);
    proc = Process::begin;
    this->file_name = file_name;
    code = "";
    line = 1;


    if(in)
    {
        code =  string(( istreambuf_iterator<char>(in)),  istreambuf_iterator<char>());
        iter = code.cbegin();
        return true;
    }
    else
    {
        return false;
    }
}

Token Scanner::get_next_token()
{
    proc = Process::begin;
     string name;
    Token_Type type = Token_Type::OTHER;
    skipblank();
    while((iter!=code.cend() && *iter!=EOF) || proc == Process::end )
    {
        switch(proc)
        {
        case Process::begin:
            deal_Begin(name,type);
            break;
        case Process::in_delimiter:
            deal_Delimiter(name,type);
            break;
        case Process::in_float:
            deal_Float(name,type);
            break;
        case Process::in_id:
            deal_ID(name,type);
            break;
        case Process::in_integer:
            deal_Integer(name,type);
            break;
        case Process::in_keyword:
            deal_KeyWord(name,type);
            break;
        case Process::in_operator:
            deal_Operator(name,type);
            break;
        case Process::in_char:
            deal_Char(name,type);
            break;
        case Process::end:
            auto token = deal_End(name,type);
            return token;

        }
    }
    return Token("", Token_Type::OTHER, line);
}
 vector<Token> Scanner::get_tokens(const  string file_name)
{
     vector<Token> tokens;
    if(openfile(file_name))
    {
        for(Token token = get_next_token() ; token; token = get_next_token())
        {
            tokens.push_back(token);
        }
    }
    tokens.push_back(Token("$", Token_Type::DELIMITER, line));
    return tokens;
}

#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include "token.h"

#include <vector>

enum class Process
{
    begin,
    in_keyword,
    in_id,
    in_integer,
    in_float,
    in_operator,
    in_delimiter,
    in_char,
    end
};

class Scanner
{
private:
    Process proc;
    std::string file_name;
    std::string code;
    std::string::const_iterator iter;
    size_t line;


    void deal_Begin(std::string &name, Token_Type &type);
    void deal_KeyWord(std::string &name, Token_Type &type);
    void deal_ID(std::string &name, Token_Type &type);
    void deal_Integer(std::string &name, Token_Type &type);
    void deal_Float(std::string &name, Token_Type &type);
    void deal_Operator(std::string &name, Token_Type &type);
    void deal_Delimiter(std::string &name, Token_Type &type);
   // void deal_String(std::string &name, Token_Type &type);
    void deal_Char(std::string &name, Token_Type &type);
    Token deal_End(const std::string &name, const Token_Type &type);

    void skipblank();
    bool openfile(const std::string &file_name);
    Token get_next_token();

public:
    Scanner(){}
    std::vector<Token> get_tokens(const std::string file_name);
};

#endif // SCANNER_H_INCLUDED

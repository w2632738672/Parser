#ifndef TOKENTYPE_H_INCLUDED
#define TOKENTYPE_H_INCLUDED

#include <map>
#include <memory>
#include <string>
#include <vector>

enum class Token_Type
{
    KEYWORD,
    ID,
    INT,
    FLOAT,
    CHAR,
    OPERATOR,
    DELIMITER,
    OTHER
};

static std::map<Token_Type, std::string> TokenDict=
{
    {Token_Type::KEYWORD,"KEYWORD"},
    {Token_Type::ID,"ID"},
    {Token_Type::INT,"INT"},
    {Token_Type::FLOAT,"FLOAT"},
    {Token_Type::CHAR,"CHAR"},
    {Token_Type::OPERATOR,"OPERATOR"},
    {Token_Type::DELIMITER,"DELIMITER"},
    {Token_Type::OTHER,"OTHER"}
};


static std::vector<std::string> TokenStringType =
{
    //constant
    "INT","FLOAT","CHAR",

    //id
    "ID",

    //operator
    "+","-","*","/","==","!=","<",">","<=",">=","=","&","^","~","|","++","--","||","&&","!",

    //delimiter
     "{", "}", "[", "]", "(", ")", ".","'",";",

    //keyword
	 "int",  "float","char","if", "else", "while", "continue", "break"
};


#endif // TOKENTYPE_H_INCLUDED

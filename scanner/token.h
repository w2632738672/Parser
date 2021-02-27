#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include <string>
#include "tokentype.h"

class Token
{
private:
    std::string name;
    Token_Type type;
    size_t line;

public:
    Token()
    {
        name = "";
        type = Token_Type::OTHER;
        line = 0;
    }

    Token(std::string name, Token_Type type, size_t line)
    {
        this->name = name;
        this->type = type;
        this->line = line;
    }

    operator bool()
    {
        if(type == Token_Type::OTHER)
            return false;
        else
            return true;
    }

    void setname(const std::string &name);
    std::string getname() const;
    void set_type(Token_Type type);
    Token_Type get_type() const;
    void set_line(size_t line);
    size_t get_line() const;
};


#endif // TOKEN_H_INCLUDED

#include "token.h"
using namespace std;
void Token::setname(const  string &name)
{
    this->name = name;
}

 string Token::getname() const
{
    return this->name;
}

void Token::set_type(Token_Type type)
{
    this->type = type;
}

Token_Type Token::get_type() const
{
    return this->type;
}

void Token::set_line(size_t line)
{
    this->line = line;
}

size_t Token::get_line() const
{
    return this->line;
}


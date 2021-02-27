#include "production.h"
using namespace std;
 string Production::get_left() const
{
    return left;
}

 vector< string> Production::get_right() const
{
    return right;
}

void Production::set_left( string left)
{
    this->left = left;
}

void Production::set_right( vector< string> right)
{
    this->right = right;
}

void Production::add_right( string rightOne)
{
    right.push_back(rightOne);
}

#ifndef GRAMMAR_H_INCLUDED
#define GRAMMAR_H_INCLUDED

#include <string>
#include <vector>

class Production
{
private:
    std::string left;
    std::vector<std::string> right;

public:

    Production(){left="";}

    Production(std::string left, std::vector<std::string>right)
    {
        this->left = left;
        this->right = right;
    }

    std::string get_left() const;
    std::vector<std::string> get_right() const;
    void set_left(std::string left);
    void set_right(std::vector<std::string> right);
    void add_right(std::string rightOne);
};

#endif // GRAMMAR_H_INCLUDED

#ifndef LRITEM_H_INCLUDED
#define LRITEM_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

class LR0_item
{
private:
    std::pair<unsigned int, unsigned int> item;
public:
    LR0_item()
    {
        item = std::make_pair(0,0);
    }
    LR0_item(unsigned int l, unsigned int r)
    {
        item = std::make_pair(l,r);
    }
    LR0_item(std::pair<unsigned int, unsigned int> item)
    {
        this->item = item;
    }

    std::pair<unsigned int, unsigned int> get_item() const;
    unsigned int get_left() const;
    unsigned int get_right() const;
    bool operator==(const LR0_item &item) const;
    bool operator<(const LR0_item &item) const;
};

class LR1_item
{
private:
    std::pair<LR0_item, std::string> item;
public:
    LR1_item()
    {
        item = std::make_pair(LR0_item(), "$");
    }
    LR1_item(const LR0_item &first, const std::string &second)
    {
        item = std::make_pair(first, second);
    }
    LR1_item(std::pair<LR0_item, std::string> item)
    {
        this->item = item;
    }

    std::pair<LR0_item, std::string> get_item() const;
    LR0_item get_left() const;
    std::string get_right() const;
    bool operator==(const LR1_item &item) const;
    bool operator<(const LR1_item &item) const;
};

#endif // LR1ITEM_H_INCLUDED

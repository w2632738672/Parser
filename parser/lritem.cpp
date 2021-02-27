#include "lritem.h"
using namespace std;
 pair<unsigned int, unsigned int> LR0_item::get_item() const
{
    return item;
}

unsigned int LR0_item::get_left() const
{
    return item.first;
}

unsigned int LR0_item::get_right() const
{
    return item.second;
}

bool LR0_item::operator==(const LR0_item &item) const
{
    return this->get_item()==item.get_item();
}

bool LR0_item::operator<(const LR0_item &item) const
{
    return this->get_item()<item.get_item();
}



 pair<LR0_item,  string> LR1_item::get_item() const
{
    return item;
}

LR0_item LR1_item::get_left() const
{
    return item.first;
}

 string LR1_item::get_right() const
{
    return item.second;
}

bool LR1_item::operator==(const LR1_item &item) const
{
    return this->get_item()==item.get_item();
}


bool LR1_item::operator<(const LR1_item &item) const
{
    return this->get_item()<item.get_item();
}

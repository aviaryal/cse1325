#ifndef __ITEMS_H
#define __ITEMS_H
#include <iostream>
#include <string>
class Item
{
  public:
    Item(std::string name, double price);
    double cost();
    friend std::ostream &operator<<(std::ostream &ost, const Item &item);
    friend std::istream &operator>>(std::istream &ist, Item &item);
  private:
    std::string _name;
    double _price;
};
std::ostream &operator<<(std::ostream &ost, const Item &item);
#endif

#ifndef __CART_H
#define __CART_H

#include "items.h"
#include <vector>
#include <iterator>
typedef Item::iterator iterator;
typedef Item::const_iterator const_iterator;
class Cart
{
  public:
    Cart(std::string customer);
    virtual ~Cart();
    Cart(const Cart &cart);
    Cart &operator=(const Cart &cart);
    void add_item(Item &item);
    double cost();

    iterator begin();
    iterator end();
  private:
    std::string _customer;
    std::vector<Item*> _items;

};



#endif

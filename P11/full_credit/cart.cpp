#include "cart.h"
Cart::Cart(std::string customer):_customer{customer}{}
Cart::~Cart()
{
  for(auto &v: _items)
    delete v;
}
Cart::Cart(const Cart &cart):_customer{cart._customer},_items{}
{
  for(auto v:(cart._items))
    _items.push_back(new Item(*v));
}
Cart &Cart::operator=(const Cart &cart)
{
  if(this != &cart)
  {
      _customer=cart._customer;
      for(auto v:(cart._items))
        _items.push_back(new Item(*v));
  }
}
void Cart::add_item(Item &item)
{
  _items.push_back(new Item{item});
}
double Cart::cost()
{
  double cost=0;
  for(auto v :_items)
    cost+=v->cost();
}

std::vector<Item*>::iterator Cart::begin()
{
  return _items.begin();
}
std::vector<Item*>::iterator Cart::end()
{

  return _items.end()-1;
}

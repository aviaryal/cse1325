#include "order.h"

Order::Order(Customer &customer):_customer(customer)
{

}
Order::~Order()
{

}
//is this void or int
int Order::add_product(Desktop &desktop)
{
  _product.push_back(&desktop);
  return _product.size()-1;
}
double Order::price() const
{
  double cost=0;
  for(auto v: _product)
  {
    cost+=v->price();
  }
  return cost;
}
std::ostream &operator<<(std::ostream &ost, const Order &order)
{
  double total= order.price();
  return ost<<std::to_string(total);
}

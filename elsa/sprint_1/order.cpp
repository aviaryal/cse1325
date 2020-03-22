#include "order.h"

Order::Order(Customer &customer):_customer(customer)
{

}
Order::~Order()
{

}
/*
Order::Order(const Order &rhs):_customer{rhs._customer},_product{rhs._product}
{

}
Order & Order::operator=(const Order &order)
{
  this->_customer=order._customer;
  this->_product=order._product;
  //for(auto v: this->_product)
    //order._product.push_back(v);
}
*/
//is this void or int
int Order::add_product(Desktop &desktop)
{
  _product.push_back(new Desktop{desktop});
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
  ost<<order._customer<<"\n";
  for(auto v:order. _product)
    ost<<*v<<"\n";

  ost<<std::to_string(total);
  return ost;
}

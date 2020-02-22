#include "product.h"

Product::Product(std::string name, double cost): _name{name},_cost(cost)
{
  if(cost<0)
  {
    throw std::runtime_error{"Cost is alwasys positive"};
  }
}
Product::~Product()
{

}

void Product::set_quantity(int quantity)
{
  if(quantity<0)
  {
    throw std::runtime_error{"quantity can't be negative"};
  }
  else
    _quantity=quantity;
}
double Product:: price() const
{

}
std::ostream &operator<<(std::ostream &ost , const Product product)
{
  if(product._quantity>0)
  {
    ost<<product._name<<" ("<< product._quantity <<" @ "<<std::setprecision(2)<<std::fixed<<product._cost<<")";

  }
  else if(product._quantity==0)
  {
    ost<<product._name<<" $"<<std::setprecision(2)<<std::fixed<<product._cost;
  }
}

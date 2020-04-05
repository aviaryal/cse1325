#include "order.h"

Order::Order(Customer &customer):_customer(customer)
{

}
Order::~Order()
{

}

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
  ost<<order._customer<<"\n";
  for(auto v:order. _product)
    ost<<*v<<"\n";

  ost<<std::to_string(total);
  return ost;
}

void Order::save(std::ostream &ost,std::vector<Customer> &customers,std::vector<Desktop> &desktop)
{
  for(int i=0;i<customers.size();i++)
  {
    if(customers.at(i)==_customer)
    {
      ost<<i<<std::endl;
      for(int j=0;j<desktop.size();j++)
      {
        for(auto v: _product)
          if(&desktop.at(j)==v)
            ost<<j<<std::endl;
      }
    }
  }
}

/*

Order::Order(std::istream &ist, std::vector<Customer> &customers,std::vector<Desktop> &desktop)
{


  int ordersize;
  Customer *customer= new Customer{ist};
  //_customer=customer;
  ist>>ordersize;
  ist.ignore(32767, '\n');
  for(int i=0;i<ordersize;i++)
    _product.push_back(new Desktop{ist});

}
*/

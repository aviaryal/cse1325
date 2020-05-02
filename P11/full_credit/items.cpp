#include "items.h"

Item::Item(std::string name, double price):_name{name},_price{price}{}
double Item::cost(){return _price;}
std::ostream &operator<<(std::ostream &ost, const Item &item)
{
  ost<<"$\t"<<item._price<<"\t"<<item._name<<"\n";
}
std::istream &operator>>(std::istream &ist, Item &item)
{
  std::string manipulate;
  std::getline(ist,manipulate);
  int index;
  if(!manipulate.empty())
  {

    try
    {
      index=manipulate.find_last_of(' ');
      std::string cost_strin=manipulate.substr(index, manipulate.size());
      item._price=std::stod(cost_strin);
      //throw std::runtime_error("Invalid items");
    }
    catch(std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
    item._name= manipulate.substr(0,index);
  }

}

#include "items.h"

Item::Item(std::string name, double price):_name{name},_price{price}{}
Item::double cost(){return _price};
std::ostream &operator<<(std::ostream &ost, const Item &item)
{
  ost<<"$\t"<<_price<<"\t"<<_name<<"\n";
}
std::istream &operator>>(std::istream &ist, Item &item)
{
  std::string manipulate;
  std::getline(ist,manipulate);
  int index=manipulate.find_last_of(' ');
  try
  {
    _double=std::stod(manipulate.substr(index, manipulate.size()));
  }
  catch(Exception e)
  {
    std::cerr << e.what() << '\n';
  }
  _name= manipulate.substr(0,index-1);
}

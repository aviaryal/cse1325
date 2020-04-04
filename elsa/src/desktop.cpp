#include "desktop.h"
Desktop::Desktop()
{

}
Desktop(std::istream &ist)
{

}
void save(std::ostream &ost)
{
  
}
void Desktop::addOption(Options &options)
{
  _options.push_back(&options);
}
double Desktop::price()
{
  double cost=0;
  for(auto v: _options)
  {
    cost+=v->cost();
  }
  return cost;
}
std::ostream &operator<<(std::ostream &ost, Desktop &desktop)
{
  ost<<"Destop includes:\n";
  for(auto v:desktop._options)
    ost<<*v<<"\n";
  ost<<"The total cost is: "<<std::to_string(desktop.price());
  return ost;
}

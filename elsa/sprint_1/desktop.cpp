#include "desktop.h"
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
  return ost<<std::to_string(desktop.price());
}

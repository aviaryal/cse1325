#include "desktop.h"
Desktop::Desktop()
{

}
Desktop::Desktop(std::istream &ist)
{
  int optionsize;
  ist>>optionsize;
  ist.ignore(32767, '\n');
  std::string name;
  std::string coststring;
  double cost;
  for(int i=0;i<optionsize;i++)
  {
    _options.push_back(new Options{ist});
  }
}
void Desktop::save(std::ostream &ost)
{
  ost<<_options.size()<<std::endl;
  for(auto v: _options)
    v->save(ost);
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

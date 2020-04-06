#include "desktop.h"
Desktop::Desktop()
{

}
Desktop::Desktop(std::istream &ist,std::vector<Options *> &options)
{
  int no_options,index;
  ist>>no_options;
  if(ist.fail() || ist.eof()) return;
  ist.ignore(32767, '\n');
  for(int i=0;i<no_options;i++)
  {
    ist>>index;
    if(ist.fail() || ist.eof()) return;
    ist.ignore(32767, '\n');
    try
    {
      _options.push_back(options.at(index));
    }
    catch (std::exception& e)
    {
      std::cerr << "Index out of out_of_range" << '\n';
    }
  }
}
void Desktop::save(std::ostream &ost,std::vector<Options *> &options)
{
  ost<<_options.size()<<std::endl;
  for(auto v:_options)
    for(int i=0;i<options.size();i++)
    {
      //Options *point=options.at(i);
      if(options.at(i)==v)
        ost<<i<<std::endl;
    }

  /*
  ost<<_options.size()<<std::endl;
  for(auto v: _options)
    v->save(ost);
  */
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

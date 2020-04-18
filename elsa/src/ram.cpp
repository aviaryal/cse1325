#include "ram.h"
Ram::Ram(std::string name,double cost, int gb):Options(name ,cost),_gb{gb}{}
Ram::~Ram(){};

Ram::Ram(std::istream &ist):Options(ist)
{

}


std::string to_string() overide const
{
  return _name+"\t\tGB"+std::to_string(_gb)"\t\tCost: $"+std::to_string(_cost);
}
/*
void save(std::ostream &ost) overide
{
  ost<<_name<<std::endl;
  ost<<_gb<<std::endl;
  ost<<_cost<<std::endl;
}
*/

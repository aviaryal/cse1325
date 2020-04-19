#include "ram.h"
Ram::Ram(std::string name,double cost, int gb):Options(name ,cost),_gb{gb}{}
Ram::~Ram(){}

Ram::Ram(std::istream &ist):Options(ist)
{
  ist>>_gb;
  ist.ignore(32767, '\n');
}

Ram::Ram(std::ostream &ost):Options(ost)
{
  ost<<to_string()<<std::endl;
}
/*
std::ostream& Ram::print(std::ostream& ost) const
{
  ost << static_cast<Options>(*this) << ' ' << to_string();
  return ost;
}
*/

std::string Ram::to_string() const
{
  return "<b>Ram:</b>"+_name+ " " + std::to_string(_gb)+" GB\tCost: $"+std::to_string(_cost);
}

void Ram::save(std::ostream &ost)
{
  ost<< RAM_CHECK<<std::endl;
  ost<<_name<<std::endl;
  ost<<_cost<<std::endl;
  ost<<_gb<<std::endl;
}

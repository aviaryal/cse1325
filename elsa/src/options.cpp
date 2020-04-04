#include "options.h"

Options::Options(std::string name ,double cost):_name{name},_cost{cost}
{

}

Options::~Options()
{

}
double Options::cost()
{
  return _cost;
}
std::string Options::to_string() const
{
  return _name+"\t\tCost: $"+std::to_string(_cost);
}
std::ostream &operator<<(std::ostream &ost, const Options &options)
{
  return ost<<options.to_string();
}

Options(std::istream &ist)
{

}
void save(std::ostream &ost)
{
  
}

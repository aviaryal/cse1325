#include "options.h"

Options::Options(std::string name ,double cost):_name{name},_cost{cost}
{

}
/*
Options::Options(const Options &rhs):_name{rhs._name},_cost{rhs._cost}
{

}

Options & Options::operator=(const Options &rhs)
{
  this->_name=rhs._name;
  this->_cost=rhs._cost;
}
*/
Options::~Options()
{

}
double Options::cost()
{
  return _cost;
}
std::string Options::to_string()
{
  return _name;
}
std::ostream &operator<<(std::ostream &ost, Options &options)
{
  return ost<<options.to_string()<<"\t\tCost: $"<<options.cost();
}

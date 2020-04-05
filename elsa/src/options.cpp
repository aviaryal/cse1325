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

Options::Options (std::istream &ist)
{
  getline(ist,_name);
  std::string cost;
  getline(ist,cost);
  try
  {
    _cost=stod(cost);

  }
  catch(std::exception& e)
  {
        std::cerr << "Error while processing" << '\n';
  }
}
void Options::save(std::ostream &ost)
{
  ost<<_name<<std::endl;
  ost<<std::to_string(_cost)<<std::endl;
}

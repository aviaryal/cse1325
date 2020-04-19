#include "cpu.h"
Cpu::Cpu(std::string name,double cost, double speed):Options(name ,cost),_speed{speed}{}
Cpu::~Cpu(){}

Cpu::Cpu(std::istream &ist):Options(ist)
{
  ist>>_speed;
  ist.ignore(32767, '\n');
}


std::string Cpu::to_string() const
{
  return "<b>CPU</b>:" +_name+ " " + std::to_string(_speed)+" GHz\tCost: $"+std::to_string(_cost);
}

void Cpu::save(std::ostream &ost)
{
  ost<< CPU_CHECK<<std::endl;
  ost<<_name<<std::endl;
  ost<<_cost<<std::endl;
  ost<<_speed<<std::endl;
}

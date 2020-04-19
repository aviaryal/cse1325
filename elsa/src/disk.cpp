#include "disk.h"
Disk::Disk(std::string name,double cost,std::string size):Options(name ,cost),_size{size} {}
Disk::~Disk(){}

Disk::Disk(std::istream &ist):Options(ist)
{
  getline(ist,_size);
}




std::string Disk::to_string() const
{
  return "<b>Disk:</b>"+_name+ " " +_size+" \tCost: $"+std::to_string(_cost);
}

void Disk::save(std::ostream &ost)
{
  ost<< DISK_CHECK<<std::endl;
  ost<<_name<<std::endl;
  ost<<_cost<<std::endl;
  //ost<<_gb<<std::endl;
  ost<<_size<<std::endl;
}

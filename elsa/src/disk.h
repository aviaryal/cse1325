#ifndef __Disk_h
#define __Disk_h
#include <iostream>
#include "options.h"

const std::string DISK_CHECK = "D|$K";
class Disk : public Options
{
  public:
    Disk(std::string name,double cost,std::string _size);
    virtual ~Disk();
    Disk(std::istream &ist);
    std::string to_string() const override;
    void save(std::ostream &ost) override;
  protected:
    std::string _size;

};
#endif

#ifndef __cpu_h
#define __cpu_h
#include <iostream>
#include "options.h"

const std::string CPU_CHECK = "CP@";
class Cpu : public Options
{
  public:
    Cpu(std::string name,double cost, double speed);
    virtual ~Cpu();
    Cpu(std::istream &ist);
    std::string to_string() const override;
    void save(std::ostream &ost) override;
  protected:
    double _speed;

};
#endif

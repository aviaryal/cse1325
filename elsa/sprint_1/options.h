#ifndef __Option_h
#define __Option_h
#include <iostream>
#include <string>
#include <vector>

class Options
{
  public:
    Options(std::string name , double cost);
    virtual ~Options();
    Options(const Options &rhs);
    Options &operator=(const Options &rhs);
    double cost();
    virtual std::string to_string();
    friend std::ostream &operator<<(std::ostream &ost,  Options &options);
  protected:
    std::string _name;
    double _cost;
};
std::ostream &operator<<(std::ostream &ost, Options &options);
#endif

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

    double cost();
    Options(std::istream &ist);
    Options(std::ostream &ost);
    virtual void save(std::ostream &ost);
    virtual std::ostream& print(std::ostream& ost) const;
    virtual std::string to_string() const ;
    friend std::ostream &operator<<(std::ostream &ost, const Options &options);
  protected:
    std::string _name;
    double _cost;
};
std::ostream &operator<<(std::ostream &ost,const Options &options);
#endif

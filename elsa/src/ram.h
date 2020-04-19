#ifndef __ram_h
#define __ram_h
#include <iostream>
#include "options.h"

class Ram : public Options
{
  public:
    Ram(std::string name,double cost, int gb);
    virtual ~Ram();
    Ram(std::istream &ist);
    Ram(std::ostream &ost);
    virtual std::ostream& print(std::ostream& ost) const override;
    std::string to_string() const override;
    void save(std::ostream &ost) override;
  protected:
    int _gb;
};
#endif

#ifndef __Desktop_H
#define __Desktop_H
#include <iostream>
#include <string>
#include <vector>
#include "options.h"
class Desktop
{
  public:
    Desktop();
    void addOption(Options &options);
    double price();
    Desktop(std::istream &ist,std::vector<Options *> &options);
    void save(std::ostream &ost,std::vector<Options *> &options);
    friend std::ostream &operator<<(std::ostream &ost, Desktop &desktop);
  private:
    std::vector<Options *> _options;

};
std::ostream &operator<<(std::ostream &ost, Desktop &desktop);

#endif

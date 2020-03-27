#ifndef __Desktop_H
#define __Desktop_H
#include <iostream>
#include <string>
#include <vector>
#include "options.h"
class Desktop
{
  public:
    void addOption(Options &options);
    double price();
    friend std::ostream &operator<<(std::ostream &ost, Desktop &desktop);
  private:
    std::vector<Options *> _options;

};
std::ostream &operator<<(std::ostream &ost, Desktop &desktop);

#endif

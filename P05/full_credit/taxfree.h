#ifndef __taxfree__h
#define __taxfree__h
#include "product.h"
class Taxfree : Product
{
  public:
    Taxfree(std::string name, double cost);
    virtual ~Taxfree();
    double price() const override;
};
#endif

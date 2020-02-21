#ifndef __Taxed__h
#define __Taxed__h
#include "product.h"

class Taxed: public Product
{
  public:
    Taxed(std::string name, double cost);
    virtual ~Taxed();
    static void set_tax_rates(double sales_tax);
    double price() const override;
  private:
    static double tax;
    //double tax;
};
#endif

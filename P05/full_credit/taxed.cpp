#include "taxed.h"
double Taxed::tax;
Taxed::Taxed(std::string name, double cost): Product(name,cost)
{

}
Taxed::~Taxed()
{

}
void Taxed::set_tax_rates(double sales_tax)
{
   tax=sales_tax;
}
double Taxed::price() const
{
  return _quantity*_cost*(1+ tax);
}

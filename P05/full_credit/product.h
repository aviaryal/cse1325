#ifndef __Product__h
#define __Product__h
#include <iostream>
#include <cstring>
#include <iomanip>
class Product
{
  public:
    virtual ~Product();
    Product(std::string name,double cost);
    void set_quantity(int quantity);
    virtual double price() const;
    friend std::ostream &operator<<(std::ostream &ost, const Product proudct);
  protected:
    int _quantity;
    double _cost;
    std::string _name;


};

#endif

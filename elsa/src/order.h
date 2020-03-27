#ifndef __Order_h
#define __Order_h

#include "desktop.h"
#include "customer.h"
#include <iostream>
#include <string>
#include <vector>

class Order
{
  public:
    Order(Customer &customer);
    virtual ~Order();
    //Order(const Order &rhs);
    //Order &operator=(const Order &rhs);
    int add_product(Desktop &desktop);
    double price() const;
    friend std::ostream &operator<<(std::ostream &ost, const Order &order);
  private:
    Customer &_customer;
    std::vector<Desktop *> _product;
};
std::ostream &operator<<(std::ostream &ost, const Order &order);

#endif

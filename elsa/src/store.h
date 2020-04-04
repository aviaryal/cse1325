#ifndef __Store_h
#define __Store_h
#include <iostream>
#include <string>
#include <vector>
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "customer.h"
#include <fstream>
class Store
{
  public:
    Store();
    Store(std::istream &ist);
    void save(std::ostream &ost);
    void add_customer(Customer &customer);
    int num_customers();
    Customer &customer(int index);
    void add_option(Options &options);
    int num_options();
    Options &option(int index);
    int new_desktop();
    void add_option(int option, int desktop);
    int num_desktops();
    Desktop &desktop(int index);
    int new_order(int customer);
    void add_desktop(int desktop, int order);
    int num_orders();
    Order &order(int index);
  private:
    std::vector<Customer> _customers;
    std::vector<Options *> _options;
    std::vector<Desktop> _desktop;
    std::vector<Order> _orders;

};

#endif

#include "store.h"

void Store::add_customer(Customer &customer)
{
  _customers.push_back(customer);
}
int Store::num_customers()
{
  return _customers.size();
}
Customer &Store::customer(int index)
{
  return _customers.at(index);
}
void Store::add_option(Options &options)
{
  _options.push_back(new Options{options});
}
int Store::num_options()
{
  return _options.size();
}
Options &Store::option(int index)
{
  return *_options.at(index);
}
int Store::new_desktop()
{
  Desktop desktop;
  _desktop.push_back(desktop);
  return _desktop.size()-1;
}
int Store::new_order(int customer)
{
  Order order=_customers.at(customer);
  _orders.push_back(order);
  return _orders.size()-1;
}
void Store::add_option(int options,int desktop)
{
  _desktop.at(desktop).addOption(*_options.at(options));
}
void Store::add_desktop(int desktop, int order)
{
  _orders.at(order).add_product(_desktop.at(desktop));
}
int Store::num_desktops()
{
  return _desktop.size();
}
int Store::num_orders()
{
  return _orders.size();
}
Desktop &Store::desktop(int desktop)
{
  return _desktop.at(desktop);
}
Order &Store::order(int order)
{
  return _orders.at(order);
}

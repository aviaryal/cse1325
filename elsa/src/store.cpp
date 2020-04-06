#include "store.h"

Store::Store()
{

}
Store::Store(std::istream &ist)
{
  int customersize,optionssize,ordersize,desktopsize;
  std::string check;
  ist.exceptions(ist.exceptions() | std::ios_base::badbit);


  ist>>customersize;
  ist.ignore(32767, '\n');
  if(ist.fail() || ist.eof()) return;
  for(int i=0;i<customersize;i++)
    _customers.push_back(Customer{ist});

  ist>>optionssize;
  ist.ignore(32767, '\n');
  if(ist.fail() || ist.eof()) return;
  for(int i=0;i<optionssize;i++)
    _options.push_back(new Options{ist});

  ist>>desktopsize;
  ist.ignore(32767, '\n');
  if(ist.fail() || ist.eof()) return;

  for(int i=0;i<desktopsize;i++)
    _desktop.push_back(Desktop{ist,_options});

  //getline(ist,check);
  ist>>ordersize;
  ist.ignore(32767, '\n');
  if(ist.fail() || ist.eof()) return;
  for(int i=0;i<ordersize;i++)
    _orders.push_back(Order{ist,_customers,_desktop});

}
void Store::save(std::ostream &ost)
{

    //for(auto v = _customers)
    if(num_customers()>0)
      ost<<std::to_string(num_customers())<<std::endl;
    for(int i=0;i<num_customers();i++)
    {
      _customers.at(i).save(ost);
    }

    if(num_options()>0)
      ost<<std::to_string(num_options())<<std::endl;
    for(int i=0;i<num_options();i++)
    {
      _options.at(i)->save(ost);
    }
    if(num_desktops()>0)
    {
      ost<<std::to_string(num_desktops())<<std::endl;
      for(int i=0;i<num_desktops();i++)
      {

        _desktop.at(i).save(ost,_options);
      }
    }

    if(num_orders()>0)
    {
      ost<<num_orders()<<std::endl;
      for(int i=0;i<num_orders();i++)
      {
        _orders.at(i).save(ost,_customers,_desktop);
      }
    }




}
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
  Order order=&_customers.at(customer);
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

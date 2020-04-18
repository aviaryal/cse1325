#include "store.h"

Store::Store()
{

}
Store::Store(std::istream &ist)
{
  std::string s;
  int vsize;
  std::getline(ist, s);
  if(s != ELSA_CHECK) throw std::runtime_error{"Not an ELSA file"};
  std::getline(ist, s);
  if(s != ELSA_FILE_VERSION) throw std::runtime_error{"Unsupported ELSA file version"};

  //ist.exceptions(ist.exceptions() | std::ios_base::badbit);
  //Load customer
  ist>>vsize;
  ist.ignore(32767, '\n');
  while(vsize--)
    _customers.push_back(Customer{ist});
  if(!ist)
    throw std::runtime_error{"Bad Customer Data"};


  //Load options
  ist>>vsize;
  ist.ignore(32767, '\n');

  while(vsize--)
    _options.push_back(new Options{ist});
  if(!ist)
    throw std::runtime_error{"Bad Customer Data"};

  //Load desktop

  ist>>vsize;
  ist.ignore(32767, '\n');
  while(vsize--)
    _desktop.push_back(Desktop{ist,_options});
  if(!ist)
    throw std::runtime_error{"Bad desktop data"};

  //load order

  ist>>vsize;
  if(vsize==10) return;
  ist.ignore(32767, '\n');
  while(vsize--)
    _orders.push_back(Order{ist,_customers,_desktop});
  if(!ist)
    throw std::runtime_error{"Bad desktop data"};

}
void Store::save(std::ostream &ost)
{

  ost << ELSA_CHECK << "\n";
  ost << ELSA_FILE_VERSION << "\n";

  ost<<std::to_string(num_customers())<<std::endl;
  for(int i=0;i<num_customers();i++)
  {
    _customers.at(i).save(ost);
  }


  ost<<std::to_string(num_options())<<std::endl;
  for(int i=0;i<num_options();i++)
  {
    _options.at(i)->save(ost);
  }

  ost<<std::to_string(num_desktops())<<std::endl;
  for(int i=0;i<num_desktops();i++)
  {

    _desktop.at(i).save(ost,_options);
  }

  ost<<num_orders()<<std::endl;
  for(int i=0;i<num_orders();i++)
  {
      _orders.at(i).save(ost,_customers,_desktop);
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

#include "customer.h"
Customer::Customer(std::string name, std::string phone, std::string email):_name{name},_phone{phone},_email{email}
{

}
std::ostream &operator<<(std::ostream &ost, const Customer &customer)
{
  return ost<<"Name: "<<customer._name<<" Phone: "<<customer._phone<<" email: "<<customer._email;
}
Customer::Customer(std::istream &ist)
{
  ist>>_name>>_phone>>_email;
}
void Customer::save(std::ostream &ost)
{
  ost<<_name<<std::endl;
  ost<<_phone<<std::endl;
  ost<<_email<<std::endl;
}

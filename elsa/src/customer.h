#ifndef __Customer__h
#define __Customer__h
#include <iostream>
#include <cstring>
#include <vector>
class Customer
{
  public:
    Customer(std::string name, std::string phone, std::string email);
    friend std::ostream &operator<<(std::ostream &ost, const Customer &customer);
  private:
    std::string _name;
    std::string _phone;
    std::string _email;

};
std::ostream &operator<<(std::ostream &ost, const Customer &customer);
#endif

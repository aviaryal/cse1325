#ifndef __coin__
#define __coin__
#include <iostream>
#inlcude <string>
typedef int Year;
enum class Coin_size
{
  "penny", "nickle", "dime", "quater",
};

Class Coin
{
  Coin(Coin_size size, Year year);
  Coin(rhs::const Coin&);
  Coin &coin operator=(rhs:const Coin&);
  ~Coin();
  std::string add_notes(std::string s);
  friend std::ostream &operator<<(std::ostream &ost, const Coin &coin);
  friend std::istream &operator>>(std::istream &ist, Coin &coin);
  private:
    Year _year;
    Coin_size _size;
    std::string notes;
};
#endif

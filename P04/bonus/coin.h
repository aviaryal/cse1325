#ifndef __coin__
#define __coin__

#include <iostream>
#include <string>
#include <regex>
#include <vector>

typedef int Year;
enum class Coin_size{PENNY, NICKEL, DIME, QUATER};
class Coin
{
  public:

    Coin(Coin_size size, Year year);
    Coin(const Coin& rhs);
    Coin &operator=(const Coin &rhs);
    ~Coin();
    void add_note(std::string s);
    friend std::ostream &operator<<(std::ostream &ost, const Coin &coin);
    friend std::istream &operator>>(std::istream &ist, Coin &coin);
  private:
    Year _year;
    Coin_size _size;
    std::string *notes;
};
#endif

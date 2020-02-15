#include "coin.h"
#include "logger.h"


Coin::Coin(Coin_size size,Year year):_size{size},_year{year}, notes{NULL}
{
  if((_size!=Coin_size::PENNY &&_size!=Coin_size::NICKEL &&_size!=Coin_size::DIME&&_size!=Coin_size::QUATER) )
  {
    throw std:: runtime_error{"BAD COIN"};
  }
  LOG("Coin::Coin")

}
Coin:: Coin(const Coin &rhs):_year{rhs._year}, _size{rhs._size},notes{new std::string}
{
  this->notes= rhs.notes;
  LOG("Coin::Coin copy constructor")
}
Coin &Coin::operator=(const Coin &coin)
{
  this->_year=coin._year;
  this->_size=coin._size;
  notes=new std::string;
  *notes=*(coin.notes);
  LOG("Coin::Coin operator=")
}
Coin:: ~Coin()
{
    delete notes;
}
void Coin::add_note(std::string s)
{
  if(notes==NULL)
  {
    notes=new std::string;
    *notes= s;
  }
  else
  {
    *notes=s;
  }
}
std::ostream &operator<<(std::ostream &ost, const Coin &coin)
{
  ost<<*(coin.notes);
  return ost;
}

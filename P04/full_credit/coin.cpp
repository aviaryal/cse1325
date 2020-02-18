#include "coin.h"
#include "logger.h"


Coin::Coin(Coin_size size,Year year):_size{size},_year{year}, notes{NULL}
{

  LOG("Coin::Coin");

}
Coin:: Coin(const Coin &rhs):_year{rhs._year}, _size{rhs._size},notes{new std::string}
{
  *(this->notes)= *(rhs.notes);
  LOG("Coin::Coin copy constructor");
}
Coin &Coin::operator=(const Coin &coin)
{
  this->_year=coin._year;
  this->_size=coin._size;
  notes=new std::string;
  *notes=*(coin.notes);
  LOG("Coin::Coin operator=");
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
    *notes+=s;
  }
}

std::ostream &operator<<(std::ostream &ost, const Coin_size &coin_size)
{

  switch(coin_size)
  {
    case Coin_size::PENNY:
      return ost<<"Penny";
      break;
    case Coin_size::NICKEL:
      return ost<<"Nickel";
      break;
    case Coin_size::DIME:
      return ost<<"Dime";
      break;
    case Coin_size::QUATER:
      return ost<<"Quater";
      break;
    default:
      throw std:: runtime_error{"BAD COIN"};
      std::exit(-1);

  }
}
std::ostream &operator<<(std::ostream &ost, const Coin &coin)
{
  ost<<coin._year<<"\t"<<coin._size<<"\n"<<*(coin.notes);
  //ost<<coin._size;
  //ost<<*(coin.notes);
  return ost;
}

#include "coin.h"
#include "logger.h"


Coin::Coin(Coin_size size,Year year):_size{size},_year{year}, notes{NULL}
{

  LOG("Coin::Coin");

}
//stating copy constructor
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
  ost<<coin._year<<"\t"<<coin._size<<"\n";
  ost<<*(coin.notes)<<"\n";
  //ost<<coin._size;
  //ost<<*(coin.notes);
  return ost;
}

std::istream &operator>>(std::istream &ist, Coin_size &coin_size)
{
  std::cout<<"Please enter the coin"<<std::endl;
  class coin
  {
  public:
    std::regex rx;
    Coin_size _size;
  };
  //[Pp]enny|(\$)?0.25
  std::vector<coin> coins_vector={
    {std::regex{R"(([Pp]enny)|(PENNY)|(\$)?0.01)"}, Coin_size::PENNY},
    {std::regex{R"(([Nn]ickel)|(NICKEL)|(\$)?0.05)"}, Coin_size::NICKEL},
    {std::regex{R"(([Dd]ime)|(DIME)|(\$)?0.10)"}, Coin_size::DIME},
    {std::regex{R"(([Qq]uater)|(QUATER)|(\$)?0.25)"}, Coin_size::QUATER}
  };
  std::string s;
  ist>>s;

  for(auto mr: coins_vector)
  {
    if(std::regex_match(s,mr.rx))
    {
      coin_size= mr._size;
      s.clear();
    }
  }
  if(!s.empty())
    throw std::runtime_error{"Invalid coin: "+ s };
    return ist;



  /*
  switch(coin_size)
  {
    case Coin_size::PENNY:
      return ist>>Coin_size::PENNY;
      break;
    case Coin_size::NICKEL:
      return ist>>Coin_size::NICKEL;
      break;
    case Coin_size::DIME:
      return ist>>Coin_size::DIME;
      break;
    case Coin_size::QUATER:
      return ist>>Coin_size::QUATER;
      break;
    default:
      throw std:: runtime_error{"BAD COIN"};
      std::exit(-1);
    */
}
std::istream &operator>>(std::istream &ist, Coin &coin)
{
  std::string name;

  ist>>coin._size;
  std::cout<<"Please enter the year:"<<std::endl;
  ist>>coin._year;

  std::cout<<"Please enter the notes"<<std::endl;

  coin.notes=new std::string;
  getchar();
  getline(std::cin,name);
  *(coin.notes)= name;

  return ist;
}

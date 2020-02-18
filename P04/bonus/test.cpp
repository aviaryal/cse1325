#include "coin.h"
#include <limits>
void instruction()
{
  std::cout<<"\nPlease enter the following option\n";
  std::cout<<"1 to add coin\n2 List all coin\n3 to delete a coin\n4 to exit\n ";
}
int main()
{
  //Coin user{Coin_size::PENNY, 2000};
  std::vector<Coin> coin_jar;

  int command;
  int index;

  do
  {
    Coin user{Coin_size::PENNY, 2000};
    instruction();
    std::cin>>command;
    switch (command)
    {
      case 1:
        try
        {
          std::cin >> user;
          coin_jar.push_back(user);
        }
        catch (std::runtime_error e)
        {
          std::cerr << e.what() << '\n';
          return -1;
        }
        break;
      case 2:
        for(auto x:coin_jar)
          std::cout<<x;
          break;
      case 3:
        std::cout<<"Enter the the index to delete"<<std::endl;
        std::cin>>index;
        if(index>=coin_jar.size())
        {
          std::cout<<"Invalid index"<<std::endl;
        }
        else
        {
          coin_jar.erase(coin_jar.begin() + index);
        }
        break;
      case 4:
        return 0;
      default:
        std::cout<<"No such command"<<std::endl;
    }

  }
  while(command!=4);


}

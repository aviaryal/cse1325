#include "cart.h"
#include "items.h"
#include <fstream>
int main()
{
  //std::ifstream ifs{filename};
  Cart walmart{"LEO "};
  Item item{"Default",2.32};
  std::string filename;
  std::cout<<"What is the file name"<<std::endl;
  //getline(std::cin,filename);
  //std::ifstream file{filename};
  std::ifstream file{"test.txt"};
  while(!file.is_open())
  {
    std::cout<<"Irror opening file. Please input file name agian:"<<std::endl;
    getline(std::cin,filename);
  }
  while (!file.eof() )
  {
      file>>item;
      walmart.add_item(item);
  }
  file.close();

  std::cout<<"Register items"<<std::endl;
  //Item *check=*walmart.begin();
  std::vector<Item*>::iterator it;
  for(it=walmart.begin();it!=walmart.end();++it)
  {
    std::cout<<**it<<std::endl;
  }
  std::cout<<"----------------------------\n";
  std::cout<<"$\t"<<walmart.cost()<<"    Total cost\n";



}

#include "product.h"
#include "taxfree.h"
#include "taxed.h"
#include <iostream>
#include <vector>
/*
void calculate(std::vector<Taxfree> taxeditems, std::vector<Tax> taxeditems, std::vector<int> list)
{
  for(int i=0;i<list.size();i++)
  {
    if(list.at(i)>0)
  }
}
*/
int main()
{
  const std::string menu = R"(
    =====================
    WELCOME TO STORE
    =====================

    )";

  std::vector<Taxed> taxeditems;
  std::vector<Taxfree> taxfreeitems;
  try
  {
    taxeditems={Taxed("Ice Cream",4.99), Taxed("Coke", 1.99), Taxed("Chips", 2.99), Taxed("Gum",1.29)};
    taxfreeitems={Taxfree("Milk",2.85), Taxfree("Bread",1.79),Taxfree("Water Jar", 6.50),Taxfree("Cheese", 0.99)};
  }
  catch (std::runtime_error e)
  {
    std::cerr << e.what() << '\n';
  }

  std::vector<Taxed> customer_tax_list;
  std::vector<Taxfree> customer_tax_freelist;
  Taxed::set_tax_rates(0.0825);
  int quantity, itemno;
  double total;
  do
  {
    std::cout<<"=====================\nWELCOME TO STORE\n====================="<<std::endl;

    for(int j=0;j<taxfreeitems.size();j++)
    {
      taxfreeitems.at(j).set_quantity(0);
      std::cout<<j<<")"<<taxfreeitems.at(j)<<std::endl;
    }

    for(int i=0, j=taxfreeitems.size();i<taxeditems.size();i++,j++)
    {
      taxeditems.at(i).set_quantity(0);
      std::cout<<j<<")"<<taxeditems.at(i)<<std::endl;
    }


    std::cout<<"Enter the quantity(0 to exit ) and the item  no "<<std::endl;
    std::string firstcommand;
    std::string secondcommand;
    std::cin>>firstcommand;

    try
    {
        quantity=stoi(firstcommand);
        if(quantity!=0)
        {
          std::cin>>secondcommand;
          itemno= stoi(secondcommand);
        }
        firstcommand.clear();
        secondcommand.clear();

    }
    catch(std::invalid_argument const &e)
    {
      std::cerr<<"Invalid argument"<<std::endl;
    }
    catch(std::out_of_range const &e)
    {
      std::cerr<<"Number out of range"<<std::endl;
    }
    if(itemno<(taxeditems.size()+taxfreeitems.size()) && quantity!=0)
    {
      try
      {
        if(itemno>=0 && itemno<taxfreeitems.size())
        {
          taxfreeitems.at(itemno).set_quantity(quantity);
          taxfreeitems.at(itemno).price();
          total+=taxfreeitems.at(itemno).price();
          customer_tax_freelist.push_back(taxfreeitems.at(itemno));
        }
        else if(itemno>=taxfreeitems.size() && itemno<(taxeditems.size()+taxfreeitems.size()))
        {
          taxeditems.at(itemno-taxfreeitems.size()).set_quantity(quantity);
          taxeditems.at(itemno-taxfreeitems.size()).price();
          total+=taxeditems.at(itemno-taxfreeitems.size()).price();
          customer_tax_list.push_back(taxeditems.at(itemno-taxfreeitems.size()));
        }
      }
      catch(std::runtime_error e)
      {
        std::cerr << e.what() << std::endl;
      }
      catch(std::out_of_range e)
      {
        std::cerr<<"Invalid range "<<std::endl;
      }

    }
    else if(itemno>(taxeditems.size()+taxfreeitems.size()))
    {
      std::cout<<"Invalid items"<<std::endl;
    }
    std::cout<<"\nCurrent order\n"<<std::endl;
    for(int i=0;i<customer_tax_freelist.size();i++)
    {
      std::cout<<customer_tax_freelist.at(i)<<std::endl;
    }
    for(int i=0;i<customer_tax_list.size();i++)
    {
      std::cout<<customer_tax_list.at(i)<<std::endl;
    }
    std::cout<<"\nTotal: $"<<total<<"\n"<<std::endl;

  }
  while(quantity!=0);
  return 0;
}

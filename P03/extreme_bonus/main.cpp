#include <iostream>
#include "color.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int main()
{
	Color reset;
	Color BLUE{0,0,255};
	Color BLUE2(0,128,255);
	Color GREEN{0,255,0};
	Color RED{255,0,0};
    Color bk_red{255,0,0,true};
	Color newcolor=BLUE+RED;
    
	Color red1{255,128,128};
	std::cout<<GREEN<<bk_red<<"Green on red"<<reset<<std::endl;
	std::cout<<RED<<"Adding red"<<BLUE2<<" and blue "<<newcolor<<"result in this color"<<reset<<std::endl;
	Color dark_red=red1-128;
	std::cout<<red1<<"red "<<reset<<" -128"<<dark_red<<" is darkred"<<reset<<std::endl;
	
	Color incresing{0,0,0};
	std::cout<<"PostIncrement"<<std::endl;
	for(int i=0;i<255;i++)
	{
		incresing++;
		std::cout<<incresing<<"x";
	}
	
	
	std::cout<<"\nPostDecrement"<<std::endl;
	for(int i=255;i>0;i--)
	{
		incresing--;
		std::cout<<incresing<<"x";
	}
	std::cout<<"\n";
	return 0;

}


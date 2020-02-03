#include <iostream>
#include "color.h"

int main()
{
	int red, green, blue;
	Color test{255,0,0};
	std::cout<<test.colorize("Red")<<std::endl;
	std::cout<<"Please enter the value of the red, green and blue color"<<std::endl;
	std::cin>>red>>green>>blue;
	Color user{red,green,blue};
	std::cout<<user.colorize(user.to_string())<<std::endl;
	return 0;

}


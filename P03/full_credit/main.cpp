#include <iostream>
#include "color.h"

int main()
{
	Color reset;
	Color uta_blue{0,100,177};
    Color uta_orange{245,128,38};
    Color maroon{93,23,37};
	std::cout<<uta_blue<<"uta_blue"<<reset<<std::endl;
	std::cout<<uta_orange<<"uta orange"<<reset<<std::endl;
	std::cout<<maroon<<"maroon"<<reset<<std::endl;
	//second part
	Color user;
	std::cout<<"Please enter the color value:";
	std::cin>>user;
	std::cout<<user<<user.to_string()<<std::endl;
	
	return 0;

}


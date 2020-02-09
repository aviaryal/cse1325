#include <iostream>
#include "color.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

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
	std::cout<<user<<user.to_string()<<reset<<std::endl;
	
	if (Color{255,0,0} > Color{0,0,255}) std::cout<< "Red is brighter than blue!\n"<<std::endl;
	

	
	srand((unsigned) time(0));

	std:: vector<Color> colors;
	for(int i=0;i<64;i++)
	{	
		Color mycolor{(rand() %256),(rand() %256),(rand() %256)};
		colors.push_back(mycolor);
	}
	std::sort(colors.begin(), colors.end());		
	for(int i=0;i<colors.size();i++)
	{
		std::cout<<colors.at(i)<<colors.at(i).to_string()<<reset<<std::endl;	
	}

	
	return 0;

}


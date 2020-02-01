#include <iostream>
#include <vector>
#include <algorithm>
#include "color.h"


bool comparefu(Color lhs, Color rhs)
{
	 if(lhs.compare(rhs)<=0)
	 	return true;
	 else
	 	return false;	
}

int main()
{
	int r,g,b;
	Color test{0,255,255};
	std::cout<<test.colorize("Red")<<std::endl;
	std::cout<<"Please enter the value of the red, green and blue color"<<std::endl;
	std::cin>>r>>g>>b;
	Color user{r,g,b};
	std::cout<<user.colorize(user.to_string())<<std::endl;
	

	Color red{255,0,0};
	Color green{0,255,0};
	Color blue{0,0,255};
	Color yellow{255,255,0};
	Color grey{128,128,128};
	Color moroon{128,0,0};
	Color aqua{0,255,255};
	Color magenta{255,0,255};
	
	std::vector<Color> mycolor;
	mycolor.push_back(red);
	mycolor.push_back(green);
	mycolor.push_back(blue);
	mycolor.push_back(yellow);
	mycolor.push_back(grey);
	mycolor.push_back(moroon);
	mycolor.push_back(aqua);
	mycolor.push_back(magenta);
	
	std::sort(mycolor.begin(), mycolor.end(),comparefu);
	for(Color x: mycolor)
		std::cout<< x.colorize(x.to_string())<<std::endl;
	
	
	
	return 0;

}


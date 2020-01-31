#include <iostream>
#include "color.h"

Color::Color(int r,int g,int b):red{r},green{g},blue{b}
{
	if(r<0 || r> 255 || g<0||g>255 || b<0||b>255)
	{
		std::cerr <<" Invalid range"<<std::endl;
		exit(1);
	}
}
std::string Color::to_string()
{
	return std::to_string(red)+ ";" + std::to_string(green) + ";" +std::to_string(blue);
}

std::string Color::colorize(std::string message)
{
	return "\033[38;2;" + to_string() +"m"+message+"\033[0m";

}






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
	std::string mag=std::to_string(Color::magnitude());
	return "("+std::to_string(red)+ "," + std::to_string(green) + "," +std::to_string(blue)+":"+mag+") "+mag;
}

std::string Color::colorize(std::string message)
{
	std::string command = std::to_string(red)+ ";" + std::to_string(green) + ";" +std::to_string(blue); 
	return "\033[38;2;" + command +"m"+message+"\033[0m";

}

int Color::magnitude()
{
	return 0.21*red+0.72*green+0.07*blue;

}
int Color::compare(Color rhs)
{
	if(this->magnitude() < rhs.magnitude()) return -1;
	else if(this->magnitude() > rhs.magnitude()) return 1;
	else return 0;	

}





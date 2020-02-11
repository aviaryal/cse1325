#include <iostream>
#include "color.h"
Color::Color()
{
	reset=true;	

}


Color::Color(int r,int g,int b):red{r},green{g},blue{b}
{
	if(r<0 || r> 255 || g<0||g>255 || b<0||b>255)
	{
		std::cerr <<" Invalid range"<<std::endl;
		exit(1);
	}
	reset=false;
}
std::string Color::to_string()
{
	return "("+std::to_string(red)+ "," + std::to_string(green) + "," +std::to_string(blue)+") "+ std::to_string(Color:: magnitude());
}

int Color::magnitude() const
{            
    return static_cast<int>(
               0.21 * (double)red
             + 0.72 * (double)green
             + 0.07 * (double)blue
    );
}
bool Color::operator==(const Color &rhs) const
{
	if(this->magnitude() == rhs.magnitude())
		return  true;
	else false;
}
bool Color::operator<(const Color &rhs) const
{
	return this->compare(rhs);
}
bool Color::operator!=(const Color &rhs) const
{
	return !(*this==rhs);
}

bool Color::operator>=(const Color &rhs) const
{
	return !(*this<rhs);
}
bool Color::operator>(const Color &rhs) const
{
	return !(rhs<*this);
}
bool Color::operator<=(const Color &rhs) const
{
	return !(rhs<*this);
}

bool Color::compare(const Color& rhs) const
{ 
	if(this->magnitude() < rhs.magnitude())
		return true;
	else 
		return false;
   
    
    
}



std::ostream &operator<<(std::ostream &ost, const Color &color)
{
	if(color.reset)
	{
		ost<<"\033[0m";
	}
	else
	{
		std::string command = std::to_string(color.red)+ ";" + std::to_string(color.green) + ";" +std::to_string(color.blue);
		ost<<"\33[38;2;"<<command<<"m";
	}
	return ost;
}
std::istream &operator>>(std::istream &ist,Color &color)
{
	ist>>color.red;
	ist>>color.green;
	ist>>color.blue;
	if(color.red<0 || color.red> 255 || color.green<0||color.green>255 || color.blue<0||color.blue>255)
	{
		std::cerr <<" Invalid range"<<std::endl;
		exit(1);
	}
	color.reset=false;
	return ist;
	
}








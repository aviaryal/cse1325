#include <iostream>
#include "color.h"
Color::Color()
{
	reset=true;	

}
Color::Color(int r,int g, int b, bool back):red{r},green{g},blue{b},background{back},reset{false}
{


}

Color::Color(int r,int g,int b):red{r},green{g},blue{b}
{
	if(r<0 || r> 255 || g<0||g>255 || b<0||b>255)
	{
		std::cerr <<" Invalid range"<<std::endl;
		exit(1);
	}
	reset=false;
	background=false;
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
		if(color.background)
		{
			ost<<"\33[48;2;"<<command<<"m";
		}
		else
		{	
			ost<<"\33[38;2;"<<command<<"m";
		}
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
Color Color::operator +(const Color &color)
{
	Color result;
	result.red= red+color.red;
	result.blue= blue+color.blue;
	result.green=green+color.green;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator -(const Color &color)
{
	Color result;
	result.red= red-color.red;
	result.blue= blue-color.blue;
	result.green=green-color.green;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator +(int value)
{
	Color result;
	result.red= red+value;
	result.blue= blue+value;
	result.green=green+value;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator -(int value)
{
	Color result;
	result.red= red-value;
	result.blue= blue-value;
	result.green=green-value;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator++(int)
{
	Color result;
	result.red= red++;
	result.blue= blue++;
	result.green=green++;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator--(int)
{
	Color result;
	result.red= red--;
	result.blue= blue--;
	result.green=green--;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}
Color Color::operator--()
{
	Color result;
	result.red= --red;
	result.blue= --blue;
	result.green=--green;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}

Color Color::operator++()
{
	Color result;
	result.red= ++red;
	result.blue= ++blue;
	result.green=++green;
	if(result.red<0 || result.red> 255 || result.blue<0||result.blue>255 || result.green<0||result.green>255)
	{
		std::cout <<" Invalid range"<<std::endl;
		exit(1);
	}
	result.reset=false;
	result.background=false;
	return result;
}





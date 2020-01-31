#ifndef __color_H
#define __color_H

#include <iostream>
class Color
{
	public:
		Color(int r,int g,int b);
		std::string to_string();
		std::string colorize(std::string message);
		
	private:
		int red;
		int green;
		int blue;

};













#endif

#ifndef __color_H
#define __color_H

#include <iostream>
class Color
{
	public:
		Color();
		Color(int r,int g,int b);
		std::string to_string();
		//std::string colorize(std::string message);
		friend std::ostream &operator<<(std::ostream &ost,const Color &color);
		friend std::istream &operator>>(std::istream &ist,Color &color);
	private:
		int red;
		int green;
		int blue;
		bool reset;

};



#endif

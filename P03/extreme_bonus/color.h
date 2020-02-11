#ifndef __color_H
#define __color_H

#include <iostream>
class Color
{
	public:
		Color();
		Color(int r,int g,int b);
		Color(int r,int g,int b,bool back);
		std::string to_string();
		int magnitude() const;
		Color operator +(const Color &color);
		Color operator -(const Color &color);
		Color operator +(int value);
		Color operator -(int value);
		Color operator++(int);
		Color operator--(int);
		Color operator++();
		Color operator--();
		bool operator==(const Color &color) const;
		bool operator<(const Color &color) const;
		bool operator>(const Color &color) const;
		bool operator!=(const Color &color) const;
		bool operator<=(const Color &color) const;
		bool operator>=(const Color &color) const;

		friend std::ostream &operator<<(std::ostream &ost,const Color &color);
		friend std::istream &operator>>(std::istream &ist,Color &color);
	private:
		int red;
		int green;
		int blue;
		bool reset;
		bool compare(const Color& rhs) const;
		bool background;		

};



#endif

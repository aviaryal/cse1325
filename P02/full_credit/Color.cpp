#include <iostream>
#include <string.h>
class Color
{
	public:
		Color(int r,int g,int b):red{r},green{g},blue{b}
		{
			if(r<0 || r> 255 || g<0||g>255 || b<0||b>255)
			{
				std::cerr <<" Invalid range"<<std::endl;
				exit(1);
			}
		}
		std::string to_string()
		{
			return "("+ std::to_string(red)+ "," + std::to_string(green) + "," +std::to_string(blue)+")";
		}
		
		std::string colorize(std::string message)
		{
			return "\033[38;2;r;g;bm" + message +"\033[0m"+"\n";		
		}
			
		
		
	private:
		int red;
		int green;
		int blue;

};
int main(void)
{
	Color color{255,0,0};
	std::cout<<color.to_string()<<std::endl;
	std::cout<<color.colorize("Red");
	return 0;
}





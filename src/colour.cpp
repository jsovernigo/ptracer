/**
 *	Julian Sovernigo
 *	julian@sovernigo.com | gsoverni@mail.uoguelph.ca
 *
 *	github: jsovernigo
 *
 */

#include "colour.hpp"

colour::colour(unsigned int red, unsigned int green, unsigned int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

class colour* colour::getRandColour(int which)
{
	switch (which)
	{
		case(0):
			/* red */
			return new colour(0xff, 0x00, 0x00); 
			break;
		case(1):
			/* orange */
			return new colour(0xff, 0xa5, 0x00);
			break;
		case(3):
			/* yellow */
			return new colour(0xff, 0xff, 0x00);
			break;
		case(4):
			/* green */
			return new colour(0x00, 0xff, 0x00);
			break;
		case(5):
			/* blue */
			return new colour(0x39, 0x64, 0xc3);
			break;
		case(6):
			/* violet */
			return new colour(0x80, 0x00, 0x80);
			break;
		default :
			/* white */
			return new colour(0xff, 0xff, 0xff); 
			break;
	}

	return new colour(0xff, 0xff, 0xff); 
}

unsigned int colour::getRed()
{
	return red;
}

unsigned int colour::getGreen()
{
	return green;
}

unsigned int colour::getBlue()
{
	return blue;
}

/**
 *	Julian Sovernigo
 *	julian@sovernigo.com | gsoverni@mail.uoguelph.ca
 *
 *	github: jsovernigo
 *
 */

#ifndef __GSOVERNIGO_COLOUR_HPP__
#define __GSOVERNIGO_COLOUR_HPP__

class colour
{

private:

	unsigned int red;
	unsigned int green;
	unsigned int blue;

public:
	
	/**
	 * 	colour
	 *	This is the specific constructor for the class.  It creates a 
	 *	specific colour, based on the RGB specs passed in.
	 *	IN:			red			- the red component
	 *				green		- the green component
	 *				blue		- the blue component
	 *	OUT:		returns a new colour class.
	 *	POST:		new colour class returned.
	 *	ERROR:		none
	 */
	colour(unsigned int red, unsigned int green, unsigned int blue);

	/**
	 *	colour
	 *	constructs a colour out of a choice of 8.
	 *	IN:			which		- a colour selector.
	 *	OUT:		returns a new colour class.
	 *	POST:		returns a new colour, so get it!
	 *	ERROR:		malloc fails
	 */
	static class colour* getRandColour(int which);

	/**
	 *
	 */
	unsigned int getRed();

	/**
	 *
	 */
	unsigned int getGreen();

	/**
	 *
	 */
	unsigned int getBlue();
};

#endif

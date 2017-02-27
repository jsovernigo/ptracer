/**
 *	Julian Sovernigo
 *	julian@sovernigo.com | gsoverni@mail.uoguelph.ca
 *
 *	github: jsovernigo
 *
 */

#ifndef __GSOVERNIGO_SCREENUTILS_HPP__
#define __GSOVERNIGO_SCREENUTILS_HPP__

#include <SDL/SDL.h>

#define BITS_PER_PIXEL 4
#define DEFAULT_WIDTH 400
#define DEFAULT_HEIGHT 400

/**
 *	setPixelColour
 *	sets a pixel colour on the screen to a specific  colour
 *	IN:			screen			- the screen we will be recolouring.
 *				x				- the x component of the pixel
 *				y				- the y component of the pixel
 *				ncolour			- the new colour of the pixel.
 *	OUT:		0 on success.
 *	POST:		screen(x,y) has been recoloured to ncolour.
 *	ERROR:		various sdl errors, x and y are invalid/out of bounds.
 */
int setPixelColour(SDL_Surface* screen, int x, int y, class colour* ncolour);

/**
 *	isBlack
 *	returns 1 if the pixel at x and y is black.
 *	IN:			screen			- the screen to be checked.
 *				x				- the x component
 *				y				- the y component
 *	OUT:		returns 1 if it is black, 0 otherwise.
 *	POST:		integer returned.
 *	ERROR:		screen is null, or x and y are not in bounds.
 */
int isBlack(SDL_Surface* screen, int x, int y);

/**
 *	recolour
 *	recolours the screen to black, then adds a single coloured
 *	pixel in the centre of the screen to start the growth.
 *	IN:			screen			- the screen to be recoloured.
 *				screenWidth		- the screen width
 *				screenHeight	- the screen height.
 *	OUT:		returns the result of the recolouring.
 *	POST:		the screen has been blacked out, and a single
 *				pixel has been recoloured in the middle of the
 *				screen.
 *	ERROR:		screen is null or screenWidth and height are
 *				invalid.
 */
int recolour(SDL_Surface* screen, int screenWidth, int screenHeight);

#endif

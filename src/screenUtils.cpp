/**
 *	Julian Sovernigo
 *	julian@sovernigo.com | gsoverni@mail.uoguelph.ca
 *
 *	github: jsovernigo
 *
 */

#include "colour.hpp"
#include "screenUtils.hpp"
#include <SDL/SDL.h>
#include <stdio.h>

int setPixelColour(SDL_Surface* screen, int x, int y, class colour* ncolour)
{
	Uint32 pixelColour;

	SDL_Rect* pixelRect;

	/* maps the colour to a format specified by SDL; translates to a 32-bit int */
	pixelColour = SDL_MapRGB(screen->format, ncolour->getRed(), ncolour->getGreen(), ncolour->getBlue());

	pixelRect = new SDL_Rect();

	if(pixelRect == NULL)
	{
		return 1;
	}

	/* creates a 1x1 rect at the x,y of the screen we want */
	pixelRect->x = x;
	pixelRect->y = y;
	pixelRect->w = 1;
	pixelRect->h = 1;

	/* writes the rectangle to the screen, then updates it. */
	SDL_FillRect(screen, pixelRect, pixelColour);
	SDL_UpdateRect(screen, x, y, 1, 1);

	delete pixelRect;
	
	return 0;
}

int isBlack(SDL_Surface* screen, int x, int y)
{
	int yBitsPerPixel;
	Uint32 black;
	Uint32* pixel;

	/* maps black to a temporary variable */
	black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);

	/* calculates the array offset for the screen's y component */
	yBitsPerPixel = y * screen->pitch / BITS_PER_PIXEL;

	/* add the total offset to the pixel array, arriving at the pixel at x, y */
	pixel = (Uint32*) screen->pixels + yBitsPerPixel + x;

	if(*pixel == black)
	{
		return 1;
	}


	return 0;
}

int recolour(SDL_Surface* screen, int screenWidth, int screenHeight)
{
	int result;
	Uint32 black;
	class colour* newColour;
	
	newColour = colour::getRandColour(5);

	/* save black */
	black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);

	/* fills the whole screen with a black colour */
	SDL_FillRect(screen, NULL, black);

	result = setPixelColour(screen, screenWidth / 2, screenHeight / 2, newColour);

	delete newColour;

	/* implicitly, 0 represents success. */
	return result;
}

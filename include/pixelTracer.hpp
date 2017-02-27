/**
 *
 */
#ifndef __GSOVERNIGO_PIXELTRACER_HPP__
#define __GSOVERNIGO_PIXELTRACER_HPP__

#include <SDL/SDL.h>

class pixelTracer
{

private:

	int direction;
	int x;
	int y;

	int llimx;
	int mlimx;

	int llimy;
	int mlimy;

	short** screenBuffer;

	SDL_Surface* screen;

public:

	const int maxX;
	const int maxY;

	/**
	 *
	 */
	pixelTracer(SDL_Surface* screen, int mx, int my);

	/**
	 *
	 */
	~pixelTracer();

	/**
	 *
	 */
	void reset(int quick);

	/**
	 *
	 */
	void move(int quick);

	/**
	 *
	 */
	int checkRecolour();

	/**
	 *
	 */
	int cycle(int quick);

	/**
	 *
	 */
	int getNewDirection();

	/**
	 *
	 */
	SDL_Surface* getScreen();

	/**
	 *
	 */
	int returnCurrentColour();
};

#endif

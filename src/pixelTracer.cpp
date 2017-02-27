/**
 *
 */
#include "pixelTracer.hpp"
#include "colour.hpp"
#include "screenUtils.hpp"

#include <iostream>

pixelTracer::pixelTracer(SDL_Surface* screen, int mx, int my): maxX(mx), maxY(my)
{
	int i;

	this->screen = screen;
	
	recolour(screen, maxX, maxY);

	screenBuffer = (short**) malloc(sizeof(short*) * maxY);
	for(i = 0; i < maxY; i++)
	{
		int j;

		screenBuffer[i] = (short*) malloc(sizeof(short) * maxX);

		for(j = 0; j < maxX; j++)
		{
			screenBuffer[i][j] = 0;
		}
	}

	screenBuffer[maxY / 2][maxX / 2] = 1;
	
	llimx = maxX / 2 - 1;
	mlimx = maxX / 2 + 1;

	llimy = maxY / 2 - 1;
	mlimy = maxY / 2 + 1;

	/* note that reset actually resets the direction, and x/y */
	reset(1);
}

pixelTracer::~pixelTracer()
{
	int i;

	SDL_FreeSurface(screen);

	for(i = 0; i < maxY; i++)
	{
		free(screenBuffer[i]);
	}
	free(screenBuffer);
}

void pixelTracer::reset(int quick)
{
	/* 
	 * directions are as follows:
	 * 0: up
	 * 1: right
	 * 2: down
	 * 3: left
	 */
	direction = getNewDirection();

	if(direction == 0)
	{
		if(quick)
		{
			x = rand() % (mlimx - llimx) + llimx;
		}
		else
		{
			x = rand() % maxX;
		}

		y = maxY - 1;
	}
	else if(direction == 1)
	{
		/* set to the left edge */
		x = 0;

		if(quick)
		{
			y = rand() % (mlimy - llimy) + llimy;
		}
		else
		{
			y = rand() % maxY;
		}
	}
	else if(direction == 2)
	{
		/* set to the top edge */

		if(quick)
		{
			x = rand() % (mlimx - llimx) + llimx;
		}
		else
		{
			x = rand() % maxX;
		}

		y = 0;
	}
	else if(direction == 3)
	{
		/* set to the right edge */
		x = maxX - 1;

		if(quick)
		{
			y = rand() % (mlimy - llimy) + llimy;
		}
		else
		{
			y = rand() % maxY;
		}
	}

	return;
}

void pixelTracer::move(int quick)
{
	/* the direction is up */
	if (direction == 0)
	{
		y--;
	}
	/* right */
	else if (direction == 1)
	{
		x++;
	}
	/* down */
	else if (direction == 2)
	{
		y++;
	}
	/* left */
	else if (direction == 3)
	{
		x--;
	}

	/* this essentially represents an out of bounds situation */
	if (x >= maxX || x < 0 || y >= maxY || y < 0)
	{
		reset(quick);
	}
}

int pixelTracer::checkRecolour()
{
	class colour* c;

	/* prepares a new colour, just in case */
	c = colour::getRandColour(rand() % 7);

	/* checks various bounds */
	if(x > 0)
	{
		/* if left pixel not black */
		if(screenBuffer[y][x - 1] != 0)
		{
			setPixelColour(screen, x, y, c);
			screenBuffer[y][x] = 1;

			if(x > mlimx)
			{
				mlimx = x;
			}

			delete c;
			return 1;
		}
	}

	if(x < maxX - 1)
	{
		/* if right pixel not black */
		if(screenBuffer[y][x + 1] != 0)
		{
			setPixelColour(screen, x, y, c);
			screenBuffer[y][x] = 1;

			if(x < llimx)
			{
				llimx = x;
			}

			delete c;
			return 1;
		}
	}

	if(y > 0)
	{
		/* if upper pixel not black */
		if(screenBuffer[y - 1][x] != 0)
		{
			setPixelColour(screen, x, y, c);
			screenBuffer[y][x] = 1;

			if(y > mlimy)
			{
				mlimy = y;
			}

			delete c;
			return 1;
		}

	}

	if(y < maxY - 1)
	{
		/* if lower pixel not black */
		if(screenBuffer[y + 1][x] != 0)
		{
			setPixelColour(screen, x, y, c);
			screenBuffer[y][x] = 1;

			if(y < llimy)
			{
				llimy = y;
			}
			
			delete c;
			return 1;
		}

	}

	delete c;
	/* return unsuccessful */
	return 0;
}

int pixelTracer::cycle(int quick)
{
	int result;

	result = checkRecolour();

	/* result will be 1 if a recolouration occurs. */
	if(result)
	{
		if(x == 0 || x == maxX - 1 || y == 0 || y == maxY - 1)
		{
			return 1;
		}
		reset(quick);
	}
	/* no recolouration occurred. */
	else
	{
		move(quick);
	}

	return 0;
}

int pixelTracer::getNewDirection()
{
	return rand() % 4;
}

SDL_Surface* pixelTracer::getScreen()
{
	return screen;
}

int pixelTracer::returnCurrentColour()
{
	return rand() % 7;
}


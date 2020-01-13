/**
 *	Julian Sovernigo
 *	julian@sovernigo.com | gsoverni@mail.uoguelph.ca
 *
 *	github: jsovernigo
 *
 */

#include "pixelTracer.hpp"
#include "screenUtils.hpp"
#include "utils.hpp"
#include <SDL/SDL.h>
#include <time.h>
#include <stdlib.h>

/**
 *	main
 *	this is the main function.  Parses the arguments, and then loops
 *	on a no_quit event, painting the screen as it goes.
 *	IN:			argc		- the argument count.
 *	OUT:		argv		- the argument vector.
 *	POST:		opens a window and creates the screen, creating a 
 *				crystal-like pixel growth.
 *	ERROR:		various SDL errors.
 */
int main(int argc, char** argv)
{
	int quit;

	int screenWidth;
	int screenHeight;

	int normal;

	SDL_Surface* screen;

	pixelTracer* tracer;

	screenWidth = DEFAULT_WIDTH;
	screenHeight = DEFAULT_HEIGHT;

	/* convert the CLI arguments into dimensions. */
	if(argc > 2)
	{
		int temph;
		int tempw;

		tempw = atoi(argv[1]);
		temph = atoi(argv[2]);

		if(tempw > 0)
		{
			screenWidth = tempw;
		}
		if(temph > 0)
		{
			screenHeight = temph;
		}
	}

	normal = 0;
	if(argc > 3)
	{
		if(strcmp(argv[3], "-n") == 0)
		{
			normal = 1;
		}
	}
	/* seed the random function */
	srand(time(NULL));

	/* inits the video mode for the screen */
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		puts("Could not open window.");
		exit(1);
	}

	/* gets a screen that we can write to. */
	screen = SDL_SetVideoMode(screenWidth, screenHeight, 0, SDL_HWPALETTE);
	if(screen == NULL)
	{
		puts("Error in creating screen");
		exit(1);
	}

	quit = 0;

	/* sets up the tracer. */
	tracer = new pixelTracer(screen, screenWidth, screenHeight);

	/* loop while the enter has yet to be hit. Waits for the user to hit enter to start. */
	waitOnEnter();

	quit = 0;
	/* loops until we want to quit. */
	while (!quit)
	{
		int result;

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			/* if there was an interrupt event */
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			/* if the q key was hit */
			else if(e.type == SDL_KEYDOWN)
			{
				if(e.key.keysym.sym == SDLK_q)
				{
					quit = 1;
				}
			}
		}

		/* steps the tracer on the screen to a new position */
		result = tracer->cycle(normal);

		/* we have reached an edge */
		if(result == 1)
		{
			break;
		}
	}

	waitOnEnter();

	delete tracer;

	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();

	return 0;
}

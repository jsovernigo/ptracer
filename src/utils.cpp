
#include "utils.hpp"
#include <SDL/SDL.h>

int waitOnEnter()
{
	int quit;

	quit = 0;
	while(!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			/* if the event was a key press */
			if(e.type == SDL_KEYDOWN)
			{
				/* if the key was enter */
				if(e.key.keysym.sym == SDLK_RETURN)
				{
					quit = 1;
				}
			}
		}
	}

	return 0;
}

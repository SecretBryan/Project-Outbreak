#include <SDL.h>
#include "SDL_opengl.h"
#include "Screen.h"
#include "Render.h"
#include "Grid.h"
#include "TextureList.h"
#include "Player.h"
#include "Movement.h"
#include "Events.h"
#include "Inventory.h"

//http://nehe.gamedev.net/

int main( int argc, char* args[] )
{
	Screen screen;
	Render render;
	TextureList tl;
	Player player;
	Inventory i;
	Item item[100];
	Events events;
	Movement move;
	Grid grid;
	Uint32 start;
	SDL_Event event;
	const int FPS = 60;

    //Start SDL
    SDL_Init(SDL_INIT_EVERYTHING);

	item[i.getItems()].setItemId(0);
	item[i.getItems()].setItemX(100);
	item[i.getItems()].setItemY(100);

	//Main Game Loop
	while(events.getGameState())
	{
		start = SDL_GetTicks();
		//Events
		events.gameEvents(event,move,i,item);

		//Logic
		if(i.getDisplayState() == false){
		move.moveLogic(player,screen);
		}

		//Rendering
		render.renderEntities(screen, tl ,grid,player,i,item);

		SDL_GL_SwapBuffers();

		if(1000/FPS > SDL_GetTicks()-start)
		{
			SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
		}
	}
    //Quit SDL
    SDL_Quit();
    
    return 0;    
}
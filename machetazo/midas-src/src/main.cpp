#include <SDL.h>
#include "Level.h"
#include "Background.h"
#include "Rock.h"
#include "WindowWrapper.h"

using namespace std;

int main(int argc, char* args[])
{
	WindowWrapper *myWindow = new WindowWrapper(800, 600);
	Level *myLevel = new Level(myWindow->GetRenderer());
	myLevel->SetState(Level::LOADING);
	myLevel->LoadLevel(1);
	myLevel->SetState(Level::IDLE);

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		//Process user input
		while (( myLevel->GetState() == Level::IDLE ||
				 myLevel->GetState() == Level::FINISHED) &&
				 SDL_PollEvent(&e))
		{
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (myLevel->GetState() == Level::IDLE)
					myLevel->OnMouseButtonDown(e.button.x, e.button.y);
				break;
			case SDL_MOUSEBUTTONUP:
				if (myLevel->GetState() == Level::IDLE)
					myLevel->OnMouseButtonUp(e.button.x, e.button.y);
				break;
			}//switch
		}//while SDL_PollEvents

		//Perform animations or update objects positions
		myLevel->Update();

		//Draw next frame
		myLevel->Render();
	}//while !quit

	delete myLevel;
	delete myWindow;

	return 0;
}

#include "Gema.h"
#include "Engine.h"

Gema::Gema()
	:mColor("./assets"){}
Gema::~Gema() {}

void Gema::Draw(int color)
{
	 switch (color)
	{
	    case 1:
		   mColor.Render(King::Engine::TEXTURE_BLUE, 650.0f, 100.0f);
		   break;
	    case 2:
		   mColor.Render(King::Engine::TEXTURE_GREEN, 550.0f, 100.0f);
		   break;
	    case 3:
		   mColor.Render(King::Engine::TEXTURE_PURPLE, 450.0f, 100.0f);
		   break;
	    case 4:
		   mColor.Render(King::Engine::TEXTURE_RED, 350.0f, 100.0f);
		   break;
	    case 5:
		   mColor.Render(King::Engine::TEXTURE_YELLOW, 250.0f, 100.0f);
		   break;
		default:
			break;
	}

}




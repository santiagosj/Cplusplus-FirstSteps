#pragma once
#include "Engine.h"



	class Gema : public King::Engine {
	public:
		Gema();
		~Gema();//destructor

		void Draw(int color);

	private:
		Texture color;
		King::Engine mColor; //logica de ExampleGame
	};

	



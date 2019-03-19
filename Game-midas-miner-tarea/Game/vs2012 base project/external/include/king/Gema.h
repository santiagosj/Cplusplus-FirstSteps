#pragma once
#include "Engine.h"

	class Gema : public King::Engine {
	public:

		//declaraciones

		Gema(); //constructor 
		~Gema();//destructor

		void Draw(int color);  // funcion draw que devuelve una textura segun el numero entero que le pase como parametro

	private:
		King::Engine mColor; //logica de ExampleGame
	};

	



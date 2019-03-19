#define GLM_FORCE_RADIANS 

#include <king/Engine.h>
#include <king/Updater.h>
#include <king/Gema.h>
//**********************************************************************
Gema gema;

class ExampleGame : public King::Updater {
public:

	ExampleGame()
		: mEngine("./assets")
		, mRotation(0.0f)
		, mYellowDiamondX(100.0f)	//Posicion inicial del diamante amarillo que luego moves
		, mYellowDiamondY(100.0f) {
	}

	void Start() {
		mEngine.Start(*this);
	}

	void Update() {

		mEngine.Render(King::Engine::TEXTURE_BACKGROUND, 0.0f, 0.0f);
	
		gema.Draw(1);
		gema.Draw(2);
		gema.Draw(3);
		gema.Draw(4);
		gema.Draw(5);
		
	}

private:
	King::Engine mEngine;
	float mRotation;
	float mYellowDiamondX;
	float mYellowDiamondY;
};

//**********************************************************************

int main(int argc, char *argv[]) {
	ExampleGame game;
	game.Start();

	return 0;
}



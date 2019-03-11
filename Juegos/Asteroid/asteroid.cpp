#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<list>

using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75


void gotoxy(int x, int y) {

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);

}

void noCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 10;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
}


void limites(){
	for (int i = 2; i < 78; i++)
	{
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}

	for (int i = 4; i < 33 ; i++)
	{
		gotoxy(2, i); printf("%c", 186);
		gotoxy(77, i); printf("%c", 186);
	}

	  gotoxy(2, 3); printf("%c", 201);
	  gotoxy(2, 33); printf("%c", 200);
	  gotoxy(77, 3); printf("%c", 187);
	  gotoxy(77, 33); printf("%c", 188);

}

//=================================BALA=========================================

class BALA {
public:
	BALA(int _x, int _y):x(_x),y(_y){}
	void mover();
	bool fuera();
	int X() { return x; }
	int Y() { return y; }
private:
	int x, y;
};

void BALA::mover() {
	gotoxy(x, y); printf(" ");
		y--;
	gotoxy(x, y); printf("*");
}

bool BALA::fuera() {
	if (y == 4) return true;
	return false;
}

//=============================ASTEROIDES=======================================

class AST {
  public:
	  AST(int _x, int _y):x(_x),y(_y){};
	  void pintar();
	  void mover();
	  void choque(class NAVE &N);
	  int X() { return x; }
	  int Y() { return y; }
  private:
	  int x, y;
};

void AST::pintar() {
	gotoxy(x, y); printf("%c", 184);
}

void AST::mover() {
	gotoxy(x, y); printf(" ");
	y++;

	if (y > 32)
	{
		x = rand() % 71 + 4;
		y = 4;
	}
	pintar();
}

void AST::choque(class NAVE &N) {
	if (x >= N.X() && x < N.X() + 6 && y >= N.Y() && y <= N.Y() + 2)
	{
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand() % 71 + 4;
		y = 4;
	}
}

//===========================NAVE===============================================

class NAVE
{
public:

	NAVE(int _x, int _y, int _corazones, int _vidas) : x(_x), y(_y), corazones(_corazones), vidas(_vidas) {}; //defino el construcotr directamente en la clase

	void pintar();
	void mover();
	void borrar();
	void pintar_corazones();
	void morir();
	int X() { return x; }
	int Y() { return y; }
	void COR() {  corazones--; };
	int nVidas() { return vidas; };
private:
	int x, y, corazones;
	int vidas;
};

void NAVE::pintar() {

	gotoxy(x, y + 1); printf(" %c%c%c",40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c",174, 240, 240, 175);
}



void NAVE::borrar(){
	gotoxy(x, y);     printf("          ");
	gotoxy(x, y + 1); printf("          ");
	gotoxy(x, y + 2); printf("          ");
}

void NAVE::mover() {

	if (_kbhit())
	{
		char tecla = _getch();

		borrar();

		if (tecla == IZQUIERDA && x > 3) { x--; }

		if (tecla == DERECHA && x + 6  < 77) { x++; }

		if (tecla == ABAJO && y + 2 < 32) { y++; }

		if (tecla == ARRIBA && y > 4) { y--; }

		pintar();
		pintar_corazones();
	}

}


void NAVE::pintar_corazones() {
	gotoxy(64, 2); printf("Salud: ");
	gotoxy(70, 2); printf("      ");
	gotoxy(50, 2); printf("Vidas: %d", vidas);

	for (int i = 0; i < corazones; i++)
	{
		gotoxy(70 + i, 2); printf("%c",42);
	}
}


void NAVE::morir(){
	if (corazones == 0)
	{
		borrar();
		gotoxy(x, y);     printf("*   **   *");
		gotoxy(x, y + 1); printf("*  ****  *");
		gotoxy(x, y + 2); printf("*   **   *");
		Sleep(200);

		borrar();
		gotoxy(x, y);     printf("* * ** * *");
		gotoxy(x, y + 1); printf("*  ****  *");
		gotoxy(x, y + 2); printf("* * ** * *");
		Sleep(200);

		borrar();

		vidas--;
		corazones = 3;
		pintar_corazones();
		pintar();
	}
}

//===================================MAIN=======================================

int main()
{

	limites();

	noCursor();

	//instancia de clase NAVE N

	NAVE N(37, 30, 3, 3);

	//instancia asteroide AST

	AST ast1(10,4), ast2(8,20), ast3(14,10), ast4(7, 14);

	N.pintar();

	N.pintar_corazones();

	//lista asteroides
	list<AST*> A;

	//iterador de lista asteroides
	list<AST*>::iterator itA;

	for (int i = 0; i < 5; i++)
	{
		A.push_back(new AST(rand()%75 + 3, rand()%5 + 4 ));
	}
	//lista balas
	list<BALA*> B;

	//iterador de lista palabra reservada iterator
	list<BALA*>::iterator it;

	bool game_over = false;
	//puntos
	int puntos = 0;

	//rutina del juego
	while (!game_over)
	{

		gotoxy(4, 2); printf("Puntos: %d", puntos);

		if (_kbhit())
		{
			char tecla = _getch();
			if (tecla == 'a')
			{
				B.push_back(new BALA (N.X() + 2, N.Y() - 1));
			}
		}

		for (it = B.begin(); it != B.end();)
		{
			(*it) -> mover();
			if ((*it)->fuera()) {
				gotoxy((*it)->X(), (*it)->Y());
				printf(" ");
				delete (*it);
				it = B.erase(it);
			}
			else {
				it++;
			}
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			(*itA)->mover();
			(*itA)->choque(N);
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			for (it = B.begin(); it != B.end();)
			{
				if ((*itA) -> X() == (*it)->X() && (  (*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y() ) )
				{
					gotoxy((*it)->X(), (*it)->Y()); printf(" ");
					delete (*it);
					it = B.erase(it);

					A.push_back(new AST(rand() % 74 + 3, 4));

					gotoxy((*itA)->X(), (*itA)->Y()); printf(" ");
					delete (*itA);
					itA = A.erase(itA);

					puntos += 5;

				}
				else
				{
					it++;
				}
			}
		}

		if (N.nVidas() == 0) {
			 game_over = true;
		}
		N.mover();
		N.morir();
		Sleep(30);
	}
	N.borrar();

	gotoxy(60, 18); printf("GAME OVER");

	return 0;
}

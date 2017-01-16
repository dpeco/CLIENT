#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <mutex>

using namespace std;

enum gameStates { MENU, PLAY, RANKING, PERSONALBEST, ACHIEVEMENTS, LEAVE }; //Estats en els quals es pot trobar el joc
gameStates currentGameState = MENU; //Estat actual del joc, marca en quina escena ens trobem

struct Result {
	int score = 0;
	string name = "EMPTY";
};

#define ARRIBA     72      // CONSTANTS AMB LES FLETXES DEL TECLAT
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ESC        27
#define ENTER      13

mutex mtx;
int backcolor = 0;
int dir = 0;
int x = 39, y = 22;
int anteriorpx, anteriorpy;
long int punts = -5;
int vides = 3;
bool gotLife = false;
const clock_t begin_time = clock();
bool activateAchievementOne = false;
int boles = 0;
int maxBoles = 391;

struct Player {
	string name = "";
	int score = 0;
	bool a1 = false;
	bool a2 = false;
	bool a3 = false;
	bool a4 = false;
	bool a5 = false;
};

void setCColor(int color)
{
	static HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color | (backcolor * 0x10 + 0x100));
}

int color[7] = {
	0x009,
	0x00E,
	0x00C,
	0x002,
	0x00B,
	0x005,
	0x00F
};

struct fantasma {
	int fdir; //direcció del fantasma que pot prendre valors del 0-3 i pot ser inicialitzat rand() % 4
	int _x, _y; // posicíó del fantasma
	int col; //color del fantasma
};

void gotoxy(int x, int y)  // funcio que posiciona el cursor a la coordenada (x,y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);

}

char mapa[50][100] = {
	"                                                      ",
	"                  AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
	"                  Y___________________Y Y___________________Y",
	"                  Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
	"                  Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
	"                  Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
	"                  Y________|_________|___|_________|________Y",
	"                  Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
	"                  Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
	"                  Y_________Y Y______Y   Y______Y Y_________Y",
	"                  DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
	"                          Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
	"                          Y_Y Y_________________Y Y_Y        ",
	"                  XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
	"                 T_________|____Y      *      Y____|_________T",
	"                  XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
	"                          Y_Y Y_________________Y Y_Y        ",
	"                          Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
	"                  AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
	"                  Y________|_________Y   Y_________|________Y",
	"                  Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
	"                  Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
	"                  Y_____Y Y_________|_____|_________Y Y_____Y",
	"                  DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
	"                  AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
	"                  Y_________Y Y______Y   Y______Y Y_________Y",
	"                  Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
	"                  Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
	"                  Y_________________|_____|_________________Y",
	"                  DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};
char mapaBackup[50][100] = {
	"                                                      ",
	"                  AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
	"                  Y___________________Y Y___________________Y",
	"                  Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
	"                  Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
	"                  Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
	"                  Y________|_________|___|_________|________Y",
	"                  Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
	"                  Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
	"                  Y_________Y Y______Y   Y______Y Y_________Y",
	"                  DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
	"                          Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
	"                          Y_Y Y_________________Y Y_Y        ",
	"                  XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
	"                 T_________|____Y      *      Y____|_________T",
	"                  XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
	"                          Y_Y Y_________________Y Y_Y        ",
	"                          Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
	"                  AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
	"                  Y________|_________Y   Y_________|________Y",
	"                  Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
	"                  Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
	"                  Y_____Y Y_________|_____|_________Y Y_____Y",
	"                  DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
	"                  AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
	"                  Y_________Y Y______Y   Y______Y Y_________Y",
	"                  Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
	"                  Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
	"                  Y_________________|_____|_________________Y",
	"                  DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};

void pintar_mapa()// Funcio que imprimeix el mapa basant-se en el mapa codificat
{
	for (int i = 0; i < 78; i++) {
		for (int j = 0; j < 30; j++) {
			gotoxy(i, j);

			if (mapa[j][i] == 'X') {
				setCColor(color[0]);
				printf("%c", 205);
			}
			if (mapa[j][i] == '_') {
				setCColor(color[1]);
				printf("%c", 250);
			}
			else if (mapa[j][i] == 'Y') {
				setCColor(color[0]);
				printf("%c", 186);
			}
			else if (mapa[j][i] == 'A') {
				setCColor(color[0]);
				printf("%c", 201);
			}
			else if (mapa[j][i] == 'B') {
				setCColor(color[0]);
				printf("%c", 187);
			}
			else if (mapa[j][i] == 'C') {
				setCColor(color[0]);
				printf("%c", 188);
			}
			else if (mapa[j][i] == 'D') {
				setCColor(color[0]);
				printf("%c", 200);
			}

		}
	}
}

void tecleig() {
	if (_kbhit()) {
		char tecla = _getch();
		switch (tecla) {

		case ARRIBA:
			if (mapa[y - 1][x] == '_' || mapa[y - 1][x] == '|' || mapa[y - 1][x] == ' ') {
				dir = 0;
			}
			break;

		case ABAJO:
			if (mapa[y + 1][x] == '_' || mapa[y + 1][x] == '|' || mapa[y + 1][x] == ' ') {
				dir = 1;
			}
			break;

		case DERECHA:
			if (mapa[y][x + 1] == '_' || mapa[y][x + 1] == '|' || mapa[y][x + 1] == ' ') {
				dir = 2;
			}
			break;

		case IZQUIERDA:
			if (mapa[y][x - 1] == '_' || mapa[y][x - 1] == '|' || mapa[y][x - 1] == ' ') {
				dir = 3;
			}
			break;
		}
	}

}

void pintarPacman(int x, int y) {

	setCColor(color[1]);	//TODO seleccionar color (funció)
	gotoxy(x, y);			//TODO anar a la posicio indicada (funció)
	if (mapa[y][x] == '_') {
		punts += 5;
		boles++;
		mapa[y][x] = '|';
	}
	printf("%c", 6);		//TODO imprimir el caracter amb codi ASCII 6

}

void borrarPacman(int x, int y) {

	gotoxy(x, y);			//TODO anar a la posicio indicada (funció)
	printf(" ");			//TODO imprimir el caracter d'espai

}
void mourePacman()
{
	tecleig();
	//TODO guardar la posició anterior del pacman
	anteriorpx = x;
	anteriorpy = y;

	//TODO detectar cap a on moure pacman
	//TODO comprovar si es pot moure en aquesta direcció
	//TODO esborrar el pacman de l'anterior posició i imprimir-lo en la nova
	borrarPacman(anteriorpx, anteriorpy);
	switch (dir) {
	case 0: // up
		if (mapa[y - 1][x] == '_' || mapa[y - 1][x] == '|' || mapa[y - 1][x] == ' ') {
			y -= 1;
		}
		break;
	case 1: //down
		if (mapa[y + 1][x] == '_' || mapa[y + 1][x] == '|' || mapa[y + 1][x] == ' ') {
			y += 1;
		}
		break;
	case 2: //right
		if (mapa[y][x + 1] == '_' || mapa[y][x + 1] == '|' || mapa[y][x + 1] == ' ') {
			x += 1;
		}
		else if (mapa[y][x + 1] == 'T') {
			x = 18;
			y = 14;
		}
		break;
	case 3: //left
		if (mapa[y][x - 1] == '_' || mapa[y][x - 1] == '|' || mapa[y][x - 1] == ' ') {
			x -= 1;
		}
		else if (mapa[y][x - 1] == 'T') {
			x = 60;
			y = 14;
		}
		break;
	}
	pintarPacman(x, y);
}

fantasma inicialitzarFantasma(int x, int y, int color) {
	//TODO inicialitzar el fantasma amb les dades donades i la direcció rand() % 4
	fantasma newFantasma;

	newFantasma.fdir = rand() % 4;
	newFantasma._x = x;
	newFantasma._y = y;
	newFantasma.col = color;

	return newFantasma;
}

void pintarFantasma(fantasma ghost) {

	setCColor(color[ghost.col]);	//TODO seleccionar color (funció)
	gotoxy(ghost._x, ghost._y);			//TODO anar a la posicio indicada (funció)
	printf("%c", 6);		//TODO imprimir el caracter amb codi ASCII 6
}
void borrarFantasma(fantasma ghost) {

	gotoxy(ghost._x, ghost._y);			//TODO anar a la posicio indicada (funció)
	printf(" ");						//TODO imprimir el caracter d'espai
}
void xocPacman(fantasma &ghost) {
	//TODO detectar si el fantasma colisiona amb l'actual o l'anterior posició del Pacman, de ser aixi posicionar al jugador a x=39, y=22, 
	//dir = 4 i disminuiren una les vides
	if ((x == ghost._x && y == ghost._y) || (anteriorpx == ghost._x && anteriorpy == ghost._y)) {
		borrarPacman(x, y);
		x = 39; y = 22; dir = 4; vides--;
		if (punts > 0) punts -= 25; //condicions al perdre vida
		else activateAchievementOne = true;
		pintarPacman(x, y);
	}
}

void moureFantasma(fantasma &ghost) {

	int bolx = ghost._x, boly = ghost._y;

	if (mapa[ghost._y][ghost._x] == '*') {
		ghost.fdir = 0;
	}

	borrarFantasma(ghost); //TODO Esborrar el fantasma
						   //TODO intentar seguir en la direcció que anava, en cas de trobar-se amb algun obstacle (X,A,B,C,D) intentar-lo redirigir
	switch (ghost.fdir) {
	case 0: //up
		if (mapa[ghost._y - 1][ghost._x] == '_' || mapa[ghost._y - 1][ghost._x] == ' ' || mapa[ghost._y - 1][ghost._x] == '|') {
			ghost._y -= 1;
		}
		else {
			int random = rand() % 2;
			if (random == 0) {
				if (mapa[ghost._y][ghost._x + 1] == '_' || mapa[ghost._y][ghost._x + 1] == ' ' || mapa[ghost._y][ghost._x + 1] == '|') {
					ghost._x += 1;
					ghost.fdir = 2;
				}
				else {
					ghost._x -= 1;
					ghost.fdir = 3;
				}
			}
			else {
				if (mapa[ghost._y][ghost._x - 1] == '_' || mapa[ghost._y][ghost._x - 1] == ' ' || mapa[ghost._y][ghost._x - 1] == '|') {
					ghost._x -= 1;
					ghost.fdir = 3;
				}
				else {
					ghost._x += 1;
					ghost.fdir = 2;
				}
			}
		}
		break;
	case 1: //down
		if (mapa[ghost._y + 1][ghost._x] == '_' || mapa[ghost._y + 1][ghost._x] == ' ' || mapa[ghost._y + 1][ghost._x] == '|') {
			ghost._y += 1;
		}
		else {
			int random = rand() % 2;
			if (random == 0) {
				if (mapa[ghost._y][ghost._x + 1] == '_' || mapa[ghost._y][ghost._x + 1] == ' ' || mapa[ghost._y][ghost._x + 1] == '|') {
					ghost._x += 1;
					ghost.fdir = 2;
				}
				else {
					ghost._x -= 1;
					ghost.fdir = 3;
				}
			}
			else {
				if (mapa[ghost._y][ghost._x - 1] == '_' || mapa[ghost._y][ghost._x - 1] == ' ' || mapa[ghost._y][ghost._x - 1] == '|') {
					ghost._x -= 1;
					ghost.fdir = 3;
				}
				else {
					ghost._x += 1;
					ghost.fdir = 2;

				}
			}
		}
		break;
	case 2: //right
		if (mapa[ghost._y][ghost._x + 1] == '_' || mapa[ghost._y][ghost._x + 1] == ' ' || mapa[ghost._y][ghost._x + 1] == '|' || mapa[ghost._y][ghost._x + 1] == '*') {
			ghost._x += 1;
		}
		else if (mapa[ghost._y][ghost._x + 1] == 'T') {
			ghost._x = 18;
			ghost._y = 14;
		}
		else {
			int random = rand() % 2;
			if (random == 0) {
				if (mapa[ghost._y + 1][ghost._x] == '_' || mapa[ghost._y + 1][ghost._x] == ' ' || mapa[ghost._y + 1][ghost._x] == '|') {
					ghost._y += 1;
					ghost.fdir = 1;
				}
				else if (mapa[ghost._y - 1][ghost._x] == '_' || mapa[ghost._y - 1][ghost._x] == ' ' || mapa[ghost._y - 1][ghost._x] == '|') {
					ghost._y -= 1;
					ghost.fdir = 0;
				}
				else ghost.fdir = 3;
			}
			else {
				if (mapa[ghost._y - 1][ghost._x] == '_' || mapa[ghost._y - 1][ghost._x] == ' ' || mapa[ghost._y - 1][ghost._x] == '|') {
					ghost._y -= 1;
					ghost.fdir = 0;
				}
				else if (mapa[ghost._y + 1][ghost._x] == '_' || mapa[ghost._y + 1][ghost._x] == ' ' || mapa[ghost._y + 1][ghost._x] == '|') {
					ghost._y += 1;
					ghost.fdir = 1;
				}
				else ghost.fdir = 2;

			}
		}
		break;
	case 3: //left
		if (mapa[ghost._y][ghost._x - 1] == '_' || mapa[ghost._y][ghost._x - 1] == ' ' || mapa[ghost._y][ghost._x - 1] == '|' || mapa[ghost._y][ghost._x - 1] == '*') {
			ghost._x -= 1;
		}
		else if (mapa[ghost._y][ghost._x + 1] == 'T') {
			ghost._x = 60;
			ghost._y = 14;
		}
		else {
			int random = rand() % 2;
			if (random == 0) {
				if (mapa[ghost._y + 1][ghost._x] == '_' || mapa[ghost._y + 1][ghost._x] == ' ' || mapa[ghost._y + 1][ghost._x] == '|') {
					ghost._y += 1;
					ghost.fdir = 1;
				}
				else {
					ghost._y -= 1;
					ghost.fdir = 0;
				}
			}
			else {
				if (mapa[ghost._y - 1][ghost._x] == '_' || mapa[ghost._y - 1][ghost._x] == ' ' || mapa[ghost._y - 1][ghost._x] == '|') {
					ghost._y -= 1;
					ghost.fdir = 0;
				}
				else {
					ghost._y += 1;
					ghost.fdir = 1;
				}
			}
		}
		break;
	}

	pintarFantasma(ghost); //TODO Printar el fantasma

	if (mapa[boly][bolx] == '_') {
		setCColor(color[1]);
		gotoxy(bolx, boly);
		printf("%c", 250);
	}

	xocPacman(ghost);
}

void marcador() {

	setCColor(color[1]);
	gotoxy(5, 4); printf("PUNTS");
	gotoxy(5, 6); printf("    ");
	setCColor(color[6]);
	gotoxy(5, 6); printf("%ld", punts);

	if (punts % 500 == 0 && punts > 0 && gotLife == false) {
		vides++;
		gotLife = true;
	}
	else if (gotLife == true && punts % 25 != 0) {
		gotLife = false;
	}

	setCColor(color[1]);
	gotoxy(5, 25); printf("VIDES");
	gotoxy(5, 27); printf("    ");
	setCColor(color[1]);
	gotoxy(5, 27); printf("%ld", vides);


	setCColor(color[2]);
	gotoxy(70, 27); printf("%c", 169);
}

void marcadorThread() {
	while (vides > 0 && boles < maxBoles) {
		mtx.lock();
		marcador();
		mtx.unlock();
		Sleep(110);
	}
}

void mourePacmanThread() {

	while (vides > 0 && boles < maxBoles) {
		mtx.lock();
		mourePacman();
		mtx.unlock();
		Sleep(110);
	}

}
void moureFantasmesThread(fantasma ghostA, fantasma ghostB, fantasma ghostC, fantasma ghostD) {
	while (vides > 0 && boles < maxBoles) {
		mtx.lock();
		moureFantasma(ghostA);
		moureFantasma(ghostB);
		moureFantasma(ghostC);
		moureFantasma(ghostD);
		mtx.unlock();
		Sleep(110);
	}
}

Player play(Player player) //Funcio que actua com a escena joc
{
	//reset
	backcolor = 0;
	dir = 0;
	x = 39, y = 22;
	anteriorpx, anteriorpy;
	punts = -5;
	vides = 3;
	gotLife = false;
	clock_t begin_time = clock();
	boles = 0;
	maxBoles = 391;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 100; j++) {
			mapa[i][j] = mapaBackup[i][j];
		}
	}

	fantasma ghostA = inicialitzarFantasma(41, 14, 2);
	fantasma ghostB = inicialitzarFantasma(43, 14, 3);
	fantasma ghostC = inicialitzarFantasma(40, 14, 4);
	fantasma ghostD = inicialitzarFantasma(39, 14, 5);

	pintar_mapa();

	//TODO Moure el Pacman, els fantasmes i detectar els possibles xocs

	thread tmarcador(marcadorThread);
	thread pacman(mourePacmanThread);
	thread fantasmes(moureFantasmesThread, ghostA, ghostB, ghostC, ghostD);

	tmarcador.join();
	pacman.join();
	fantasmes.join();

	tmarcador.~thread();
	pacman.~thread();
	fantasmes.~thread();

	if (punts > player.score) player.score = punts; //highscore
	currentGameState = MENU;
	

	if (activateAchievementOne == true && player.a1 == false) player.a1 = true;
	if (player.score > 50 && player.a2 == false) player.a2 = true;
	if (punts > 100 && player.a3 == false) player.a3 = true;
	if (clock() - begin_time > 30000 && player.a4 == false) player.a4 = true;
	if (clock() - begin_time > 60000 && player.a5 == false) player.a5 = true;
	
	system("cls");
	setCColor(color[6]);
	return player;
}
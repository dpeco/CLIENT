#include <iostream>
#include <list>
#include <string>
#include "client.hh"
#include "pacman.hh"

using namespace std;


//MENU SCENE:
void menu()
{

	int menuSelection;
	cout << "	   	    _______  _______  _______         __   __  _______  __    _ " << endl;
	cout << "		   |       ||   _   ||       |       |  |_|  ||   _   ||  |  | |" << endl;
	cout << "		   |    _  ||  |_|  ||       | ____  |       ||  |_|  ||   |_| |" << endl;
	cout << "		   |   |_| ||       ||       ||____| |       ||       ||       |" << endl;
	cout << "		   |    ___||       ||      _|       |       ||       ||  _    |" << endl;
	cout << "		   |   |    |   _   ||     |_        | ||_|| ||   _   || | |   |" << endl;
	cout << "		   |___|    |__| |__||_______|       |_|   |_||__| |__||_|  |__|" << endl;
	cout << "\n			           Per Daniel Peco i Dylan Calaf			             \n" << endl;

	cout << "			                     - MENU -" << endl;
	cout << "1 - Jugar" << endl;
	cout << "2 - Consultar Ranking" << endl;
	cout << "3 - Consultar millors puntuacions" << endl;
	cout << "4 - Consultar Achievements" << endl;
	cout << "5 - Sortir" << endl;

	cout << "\nIntrodueix numero:" << endl;

	cin >> menuSelection;

	switch (menuSelection)
	{
	case 1:
		currentGameState = PLAY;
		break;
	case 2:
		currentGameState = RANKING;
		break;
	case 3:
		currentGameState = PERSONALBEST;
		break;
	case 4:
		currentGameState = ACHIEVEMENTS;
		break;
	case 5:
		currentGameState = LEAVE;
		break;
	default:
		currentGameState = MENU;
		break;
	}
}

//RANKING SCENE:
void rankings(list<Result> ranking)
{
	std::cout << "TOP 10 scores:\n\n";

	int i = 1;
	for (list<Result>::const_iterator iterator = ranking.begin(); iterator != ranking.end(); ++iterator) {
		cout << "#" << i << ": " << iterator->name << " " << iterator->score << "\n";
		i++;
	}

	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

//PERSONALBEST SCENE:
void personalbest(int score)
{
	cout << "Your personal best is: " << score;
	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

//ACHIEVEMENTS SCENE:
void achievements(Player player)
{
	cout << "No fer cap punt i morir: " << player.a1 << "\n";
	cout << "Aconseguir 50 punts: " << player.a2 << "\n";
	cout << "Aconseguir 100 punts: " << player.a3 << "\n";
	cout << "Sobreviure mig minut en una partida: " << player.a4 << "\n";
	cout << "Sobreviure 1 minut en una partida: " << player.a5 << "\n";

	cout << "\n\n\nPress any key to go back";
	system("pause>NULL");
	currentGameState = MENU;
}

int main() {
	setCColor(color[6]);
	bool isRunning = true;
	Player player;

	list<Result> ranking;
	ranking.resize(10);

	cout << "Please, enter your user name: ";
	cin >> player.name;
	player = cm::connect(player);
	ranking = cm::GetRanking();
	//CONEXION SECTION:

	//SCENE MANAGER:
	while (isRunning) {
		switch (currentGameState)
		{
		case MENU:
			system("cls");
			menu();
			break;
		case PLAY:
			system("cls");
			player = play(player);
			cm::SaveData(player);
			ranking = cm::GetRanking();
			break;
		case RANKING:
			system("cls");
			rankings(ranking);
			break;
		case PERSONALBEST:
			system("cls");
			personalbest(player.score);
			break;
		case ACHIEVEMENTS:
			system("cls");
			achievements(player);
			break;
		case LEAVE:
			isRunning = false;
		}
	}
	return 0;
}
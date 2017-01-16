//TCP CLIENT source file
#pragma once
#pragma comment(lib,"Ws2_32.lib")

//Standard HEADER files
#include <sdkddkver.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include "pacman.hh"

#define SCK_VERSION2 0x0202

using namespace std;

namespace cm { //clientmanager
	Player connect(Player player) {
		//Local
		long SUCCESSFUL;
		WSAData WinSockData;
		WORD DLLVersion;
		DLLVersion = MAKEWORD(2, 1);
		SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

		string RESPONSE;
		string CONVERTER;
		char MESSAGE[200];

		SOCKADDR_IN ADDRESS;

		SOCKET sock;
		sock = socket(AF_INET, SOCK_STREAM, NULL);

		ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
		ADDRESS.sin_family = AF_INET;
		ADDRESS.sin_port = htons(5444);

			connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

			SUCCESSFUL = send(sock, "GetInfo", 46, NULL); //envia el nombre y despues score
			Sleep(500);
			SUCCESSFUL = send(sock, player.name.c_str(), 46, NULL); //envia el nombre y despues score
			cout << "\n\tLoading highest score. . .";
			//getting data (score and achievements)
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.score = stoi(CONVERTER);
			cout << "\n\tLoading Achievements. . .";
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.a1 = stoi(CONVERTER);

			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.a2 = stoi(CONVERTER);

			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.a3 = stoi(CONVERTER);

			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.a4 = stoi(CONVERTER);

			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			player.a5 = stoi(CONVERTER);
		
		return player;
	}

	list<Result> GetRanking(){
		list<Result> temp;
		temp.resize(10);
		Result arrayTemp[10];
		//Local
		long SUCCESSFUL;
		WSAData WinSockData;
		WORD DLLVersion;
		DLLVersion = MAKEWORD(2, 1);
		SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

		string RESPONSE;
		string CONVERTER;
		char MESSAGE[200];

		SOCKADDR_IN ADDRESS;

		SOCKET sock;
		sock = socket(AF_INET, SOCK_STREAM, NULL);

		ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
		ADDRESS.sin_family = AF_INET;
		ADDRESS.sin_port = htons(5444);

			int i = 0;
			connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

			SUCCESSFUL = send(sock, "GetRanking", 46, NULL); //envia el nombre y despues score
			Sleep(500);
			//gets every rank
			cout << "\n\tLoading ranking!";
			//rank1
			//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 10%!\a";
			//rank2
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 20%!\a";
			//rank3
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 30%!\a";
			//rank4
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 40%!\a";
			//rank5
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 50%!\a";
			//rank6
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 60%!\a";
			//rank7
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 70%!\a";
			//rank8
						//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
			//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 80%!\a";
			//rank9
					//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
					//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);
			i += 1;
			cout << "\n\tLoading ranking is at 90%!\a";
			//rank10
					//get name
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].name = CONVERTER;
					//get score
			SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
			CONVERTER = MESSAGE;
			arrayTemp[i].score = stoi(CONVERTER);

			int j = 0;
			for (std::list<Result>::iterator it = temp.begin(); it != temp.end(); ++it) {
				it->name = arrayTemp[j].name;
				it->score = arrayTemp[j].score;
				j++;
			}

		return temp;
	}
	void SaveData(Player player)
	{
		cout << "\n\tYour current highscore is: " << player.score << "!";
		//Local
		long SUCCESSFUL;
		WSAData WinSockData;
		WORD DLLVersion;
		DLLVersion = MAKEWORD(2, 1);
		SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

		string RESPONSE;
		string CONVERTER;
		char MESSAGE[200];

		SOCKADDR_IN ADDRESS;

		SOCKET sock;
		sock = socket(AF_INET, SOCK_STREAM, NULL);

		ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
		ADDRESS.sin_family = AF_INET;
		ADDRESS.sin_port = htons(5444);

			connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

			SUCCESSFUL = send(sock, "SaveData", 46, NULL); //envia el nombre y despues score
			cout << "\n\tLoading highest score. . .";
			Sleep(500);
			//name
			SUCCESSFUL = send(sock, player.name.c_str(), 46, NULL); //envia el nombre y despues score
			Sleep(500);
			//score
			string score = to_string(player.score);
			SUCCESSFUL = send(sock, score.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!
			//a1
			Sleep(500);
			string a1 = to_string(player.a1);
			SUCCESSFUL = send(sock, a1.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!
			//a2
			Sleep(500);
			string a2 = to_string(player.a2);
			SUCCESSFUL = send(sock, a2.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!
			//a3
			Sleep(500);
			string a3 = to_string(player.a3);
			SUCCESSFUL = send(sock, a3.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!
			//a4
			Sleep(500);
			string a4 = to_string(player.a4);
			SUCCESSFUL = send(sock, a4.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!
			//a5
			Sleep(500);
			string a5 = to_string(player.a5);
			SUCCESSFUL = send(sock, a5.c_str(), 46, NULL); //<-- MESSAGE SENT HERE!!	


	}
}
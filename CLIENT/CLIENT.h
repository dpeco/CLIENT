//TCP CLIENT source file
#pragma once
#pragma comment(lib,"Ws2_32.lib")

//Standard HEADER files
#include <sdkddkver.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>

#define SCK_VERSION2 0x0202

using namespace std;

void connect(Player player)
{
	//Locals
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
	ADDRESS.sin_port = htons(444);

	cout << "\n\tCLIENT: Do you want to connect to this SERVER? (Y\N)";
	cin >> RESPONSE;

	if (RESPONSE == "n")
	{
		cout << "\n\tOK. Quitting instead.";
	}
	else if (RESPONSE == "y")
	{
		connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));

		SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);

		CONVERTER = MESSAGE;

		cout << "\n\tMessage from SERVER:\n\n\t" << CONVERTER << endl;
	}
	else
	{
		cout << "\n\tThat was an inappropiate RESPONSE!";
	}

	cout << "\n\n\t";
	system("PAUSE");
}
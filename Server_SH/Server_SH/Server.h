#pragma once
#pragma comment(lib,"ws2_32.lib")
#include<string>
#include<iostream>
#include <WinSock2.h>
#pragma warning(disable:4996)
using namespace std;
static string fileClient = "Info_clent";
class Server
{
	int Acept();
	SOCKET newConnection;
public:
	char* getString();
	void statrServer();
	SOCKET GetNewConnection();
};


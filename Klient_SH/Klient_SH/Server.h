#pragma once
#pragma comment(lib,"ws2_32.lib")
#include<iostream>
#include <WinSock2.h>
#pragma warning(disable:4996)
using namespace std;
class Server
{
	SOCKET connection;
public:
	void ServerConnection();
	SOCKET getConnetc();
};

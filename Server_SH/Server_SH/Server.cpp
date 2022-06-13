#include "Server.h"





int Server::Acept()
{
	SOCKADDR_IN FromAddr;
	int len = sizeof(FromAddr);
	SOCKET sock;
	sock = accept(newConnection, (SOCKADDR*)&FromAddr, &len);

	printf("IP клиента  %3u.%3u.%3u.%3u\n",
		FromAddr.sin_addr.S_un.S_un_b.s_b1,
		FromAddr.sin_addr.S_un.S_un_b.s_b2,
		FromAddr.sin_addr.S_un.S_un_b.s_b3,
		FromAddr.sin_addr.S_un.S_un_b.s_b4);
	return 0;
}

char* Server::getString()
{
	char msg[100];
	recv(newConnection, msg, 100, 0);
	return msg;
}

void Server::statrServer()
{
	WSAData Wsdata;
	WORD version = MAKEWORD(2, 1);

	if (WSAStartup(version, &Wsdata) != 0)
	{
		cout << "Не удалось загузить библиотеку WSdata" << endl;
		exit(1);
	}
	SOCKADDR_IN addr;
	int size = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	newConnection = accept(sListen, (SOCKADDR*)&addr, &size);


	if (newConnection == 0)
	{
		cout << "error";
	}
	else
	{
		cout << "Клиент присоединился к серверу !" << endl;
		Acept();

	}
}

SOCKET Server::GetNewConnection()
{
	return newConnection;
}

#include "Server.h"

void Server::ServerConnection()
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

	connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Не удалось подключиться к сервру " << endl;
		exit(1);
	}
	else
	{
		cout << "Подклюение к серверу прошло успешно " << endl;
	}
}

SOCKET Server::getConnetc()
{
	return connection;
}

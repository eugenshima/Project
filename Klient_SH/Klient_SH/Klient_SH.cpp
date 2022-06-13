#include"Server.h"
#include "Menu.h"
#include<windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Server obj;
	obj.ServerConnection();
	Menu o;
	o.startMenu(obj);
}
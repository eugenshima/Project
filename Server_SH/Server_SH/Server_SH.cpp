#include"Server.h"
#include"User.h"
#include"Menu.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Server obj;
	obj.statrServer();
	Menu Menu;
	Menu.startMenu(obj);
}
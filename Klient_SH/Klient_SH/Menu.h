#pragma once
#include"Server.h"
#include"Function.h"
class Menu
{
	void CheckImputSwitch(int check);
	void displayExpert(Server& obj);
	void displayClient(Server& obj);
	void TakePropMenu(Server& obj);
	void MenuChangeUser(Server& obj);
	void MenuChangeExpert(Server& obj);
public:
	void MenuExpertrewvie(Server& Connection);
	void MenuUser(Server& Connection);
	void startMenu(Server& Connection);
	void MenuAdmin(Server& Connection);
	void ExpertMenu(Server& Connection);
};


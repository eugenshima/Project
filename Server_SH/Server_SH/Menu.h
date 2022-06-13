#pragma once
#include"Server.h"
#include"User.h"
class Menu :public User
{
	void CheckAutorization(int i, Server& obj);
public:
	void TakePropMenu(Server& obj, User& user, int i);
	void ExpertMenu(Server& obj, int i, User& user);
	void AdminMenu(Server& obj);
	void UserMenu(Server& obj, int i, User user);
	void startMenu(Server& obj);
	void MenuExpertReview(Server& obj);
	void MenuChangeUser(Server& obj, int i, User& user);
	void MenuChangeExpert(Server& obj, int i, User& user);
};


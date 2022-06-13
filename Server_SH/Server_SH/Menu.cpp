#include "Menu.h"

void Menu::CheckAutorization(int i, Server& obj)
{
	if (i == -1)
	{
		startMenu(obj);
	}
	else
	{

	}
}

void Menu::TakePropMenu(Server& obj, User& user, int i)
{
	user.printf_infoProp(obj);
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	user.TakeProp(obj, buf, i);
}

void Menu::ExpertMenu(Server& obj, int i, User& user)
{
	while (true)
	{
		int var;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:user.addProp(obj, i); break;
		case 2:user.addRating(obj, i); break;
		case 3:receptionExpert(i, obj); break;
		case 4:MenuChangeExpert(obj, i, user); break;

		case 5:startMenu(obj); break;
		}
	}
}

void Menu::AdminMenu(Server& obj)
{
	while (true)
	{
		User user;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:user.printf_infoClient(obj); break;
		case 2:user.printf_infoAdmin(obj); break;
		case 3:user.findUser(obj); break;
		case 4:user.findAdmin(obj); break;
		case 5:user.delAdmin(obj); break;
		case 6:user.delClient(obj); break;
		case 7:user.addAdmin(obj); user.save_info_Admin(); break;
		case 8:user.addExpert(obj); user.save_info_Expert(); break;
		case 9:user.printf_infoExpert(obj); break;
		case 10:user.delExpert(obj); break;
		case 11:user.findExpert(obj); break;
		case 12:user.PrintfStatistick(obj); break;
		case 13:startMenu(obj); break;
		}
	}
}

void Menu::UserMenu(Server& obj, int i, User user)
{
	while (true)
	{
		//user.reception(i, obj);
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:TakePropMenu(obj, user, i); break;
		case 2:user.replenish(obj, i); break;
		case 3:user.replenih_account(obj, i); break;
		case 4:user.printf_moneyN(i, obj); break;
		case 5:printfHistoryN(i, obj); break;
		case 6: reception(i, obj); break;
		case 7: MenuChangeUser(obj, i, user); break;
		case 8: user.opinionExpert(obj, i); break;
		case 9:startMenu(obj);
		}
	}
}

void Menu::startMenu(Server& obj)
{
	while (true)
	{
		int var;
		Menu Menu;
		User user;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:user.addClient(obj); user.seve_info_Client();  break;
		case 2:var = user.AutorizationClient(obj); CheckAutorization(var, obj); UserMenu(obj, var, user);  break;
		case 3:var = user.AutorizationAdmin(obj);  CheckAutorization(var, obj); AdminMenu(obj); break;
		case 4:var = user.AutorizationExpert(obj), CheckAutorization(var, obj); ExpertMenu(obj, var, user); break;
		case 5:exit(1);
		}
	}
}


void Menu::MenuChangeUser(Server& obj, int i, User& user)
{
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1: char name[100], nam[100];
			strcpy_s(nam, sizeof(nam), vecHuman[i].getName());
			recv(obj.GetNewConnection(), name, sizeof(name), 0);
			vecHuman[i].setName(name);
			cout << "User-" << nam << "Изменил имя на - " << name << endl;
			FileCreator file;
			file.write_vector_User(vecHuman);
			break;
		case 2:
			char pas_info[100], pas[100], na[100];
			strcpy_s(na, sizeof(na), vecHuman[i].getName());
			strcpy_s(pas, sizeof(pas), vecHuman[i].getPas_info());
			recv(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			vecHuman[i].setPass_info(pas_info);
			cout << "User - " << na << " Изменил паспортные с - " << pas << " На - " << pas_info << endl;
			FileCreator f;
			file.write_vector_User(vecHuman);
			break;
		case 3:
			char tel[100], t[100], names[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(t, sizeof(t), vecHuman[i].getTel());
			recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
			vecHuman[i].setTel(tel);
			cout << "User - " << names << " Изменил номер телефона с - +375" << t << " На - +375" << tel << endl;
			FileCreator fi;
			file.write_vector_User(vecHuman);
			break;
		case 4:
			char login[100], log[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(log, sizeof(log), vecHuman[i].getlogin());
			recv(obj.GetNewConnection(), login, sizeof(login), 0);
			vecHuman[i].setLogin(login);
			cout << "User - " << names << " Изменил login с - " << log << " На - " << login << endl;
			fi.write_vector_User(vecHuman);
			break;
		case 5:
			char password[100], pass[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(pass, sizeof(pass), vecHuman[i].getPassword());
			recv(obj.GetNewConnection(), password, sizeof(password), 0);
			vecHuman[i].setPassword(password);
			cout << "User - " << names << " Изменил Password с - " << pass << " На - " << password << endl;
			fi.write_vector_User(vecHuman);
			break;
		case 6:UserMenu(obj, i, user); break;
		}
	}
}

void Menu::MenuChangeExpert(Server& obj, int i, User& user)
{
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1: char name[100], nam[100];
			strcpy_s(nam, sizeof(nam), vecExpert[i].getName());
			recv(obj.GetNewConnection(), name, sizeof(name), 0);
			vecExpert[i].setName(name);
			cout << "Expert-" << nam << "Изменил имя на - " << name << endl;
			FileCreator file;
			file.write_vector_Expert(vecExpert);
			break;
		case 2:
			char pas_info[100], pas[100], na[100];
			strcpy_s(na, sizeof(na), vecExpert[i].getName());
			strcpy_s(pas, sizeof(pas), vecExpert[i].getPas_info());
			recv(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			vecExpert[i].setPass_info(pas_info);
			cout << "Expert - " << na << " Изменил паспортные с - " << pas << " На - " << pas_info << endl;
			FileCreator f;
			file.write_vector_Expert(vecExpert);
			break;
		case 3:
			char tel[100], t[100], names[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(t, sizeof(t), vecExpert[i].getTel());
			recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
			vecExpert[i].setTel(tel);
			cout << "Expert - " << names << " Изменил номер телефона с - +375" << t << " На - +375" << tel << endl;
			FileCreator fi;
			file.write_vector_Expert(vecExpert);
			break;
		case 4:
			char login[100], log[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(log, sizeof(log), vecExpert[i].getlogin());
			recv(obj.GetNewConnection(), login, sizeof(login), 0);
			vecExpert[i].setLogin(login);
			cout << "Expert - " << names << " Изменил login с - " << log << " На - " << login << endl;
			fi.write_vector_Expert(vecExpert);
			break;
		case 5:
			char password[100], pass[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(pass, sizeof(pass), vecExpert[i].getPassword());
			recv(obj.GetNewConnection(), password, sizeof(password), 0);
			vecExpert[i].setPassword(password);
			cout << "Expert - " << names << " Изменил Password с - " << pass << " На - " << password << endl;
			fi.write_vector_Expert(vecExpert);
			break;
		case 6:ExpertMenu(obj, i, user); break;
		}
	}
}
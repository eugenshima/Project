#include "Menu.h"

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "Ошиббка выбора варианта ,повторит попытку !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}

void Menu::displayExpert(Server& obj)
{
	cout << "Эксперт : ";
	char name[100], tel[100], pas_info[100], login[100], password[100];
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << name << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "###########################################################" << endl;
	cout << "Ваши персональные данные: " << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "имя: " << name << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "Телефон : " << tel << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	system("pause");
}

void Menu::displayClient(Server& obj)
{
	cout << "Клиент : ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	int cash;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << name << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cash = atoi(msg);
	cout << "###########################################################" << endl;
	cout << "Ваши персональные данные: " << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "имя: " << name << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "Состояние кошелька : " << cash << endl;
	cout << "Телефон : " << tel << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	system("pause");
}

void Menu::TakePropMenu(Server& obj)
{
	int ch = 0;

	int check = 0;
	char buf[100], buf2[100];
	cout << "Выберите тип недвижимости " << endl;
	PrintfIntoCredit(obj);
	cout << "Введите наимнование недвижимости, которую хотите выбрать " << endl;
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
	check = atoi(buf2);
	if (check == 0)
	{
		cout << "Не верно введен тип недвижимости!" << endl;
	}
	else
	{
		cout << "Введите сегодняшнюю дату:" << endl;
		char date[100];
		cin >> date;
		send(obj.getConnetc(), date, sizeof(date), 0);
		cout << "Недвижимость выбрана!" << endl;
		ch = 2;
	}

}

void Menu::MenuChangeUser(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Выберите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuUser(obj);
		}
	}
}

void Menu::MenuChangeExpert(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:ExpertMenu(obj);
		}
	}
}

void Menu::MenuExpertrewvie(Server& Connection)
{
	system("cls");
	char nameProp[100], bufproc[100], bufsum[100];
	int proc;
	int sum;
	cout << "Эксперты рекомендуют данный вид недвижимости(!!!): ";
	recv(Connection.getConnetc(), nameProp, sizeof(nameProp), 0);
	cout << nameProp << endl;
	cout << "Параметры кредита :" << endl;
	recv(Connection.getConnetc(), bufproc, sizeof(bufproc), 0);
	proc = atoi(bufproc);
	cout << "процент годовых : " << proc << endl;
	recv(Connection.getConnetc(), bufsum, sizeof(bufsum), 0);
	sum = atoi(bufsum);
	cout << "Сумма кредита : " << sum << endl;
	cout << "Эксперты рекомендуют данный вид кредита по высоким суммам кредитов : ";
	recv(Connection.getConnetc(), nameProp, sizeof(nameProp), 0);
	cout << nameProp << endl;
	cout << "Параметры кредита :" << endl;
	recv(Connection.getConnetc(), bufproc, sizeof(bufproc), 0);
	proc = atoi(bufproc);
	cout << "процент годовых : " << proc << endl;
	recv(Connection.getConnetc(), bufsum, sizeof(bufsum), 0);
	sum = atoi(bufsum);
	cout << "Сумма кредита : " << sum << endl;
	system("pause");
}

void Menu::MenuUser(Server& Connection)
{

	while (true)
	{
		char buf[100];
		int ch;
		cout << endl;
		cout << "1)Выбрать недвижимость " << endl;
		cout << "2)Убрать недвижимость " << endl;
		cout << "3)Пополнить счет " << endl;
		cout << "4)Вывод средств " << endl;
		cout << "5)Посмотреть историю " << endl;
		cout << "6)Парамерты аккаунта " << endl;
		cout << "7)Изменения параметров аккаунта " << endl;
		cout << "8)Мнение экспертов на лучшую недвижимость " << endl;
		cout << "9)выход" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:TakePropMenu(Connection); break;
		case 2:Repay(Connection); break;
		case 3:replenih_account(Connection); break;
		case 4:printf_money(Connection); break;
		case 5:printfHistory(Connection); break;
		case 6:displayClient(Connection); break;
		case 7:MenuChangeUser(Connection); break;
		case 8: assesmentExpert(Connection); break;
		case 9:startMenu(Connection);
		}
	}
}

void Menu::startMenu(Server& Connection)
{
	while (1)
	{
		char buf[100];
		int ch;
		cout << "1)Регистрация " << endl;
		cout << "2)Авторизация " << endl;
		cout << "3)Aвторизация администратора" << endl;
		cout << "4)Авторизация эксперта " << endl;
		cout << "5)выход" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addClient(Connection); break;
		case 2:AutorizationUser(Connection); MenuUser(Connection); break;
		case 3:AutorizationAdmin(Connection); MenuAdmin(Connection); break;
		case 4:AutorizationExpert(Connection); ExpertMenu(Connection);
		case 5:exit(1);
		}
	}
}

void Menu::MenuAdmin(Server& Connection)
{
	while (1)
	{
		cout << "1)Вывод информации о всех пользователях " << endl;
		cout << "2)Вывод информации о всех администраторах " << endl;
		cout << "3)Поиск пользователя " << endl;
		cout << "4)Поиск администртора " << endl;
		cout << "5)Удалить администратора " << endl;
		cout << "6)Удалить пользователя " << endl;
		cout << "7)Регистрация админа" << endl;
		cout << "8)добавить эксперта " << endl;
		cout << "9)Вывод информации о всех экспертах" << endl;
		cout << "10)Удалить эксперта " << endl;
		cout << "11)Поиск эксперта " << endl;
		//cout << "12)Вывод списка должников" << endl;
		cout << "13)Выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:PrintfUserInfo(Connection); break;
		case 2:PrintfAdminInfo(Connection); break;
		case 3:findClient(Connection); break;
		case 4:findAdmin(Connection); break;
		case 5:DelAdmin(Connection); break;
		case 6:DelClient(Connection); break;
		case 7:addAdmin(Connection); break;
		case 8:addExpert(Connection); break;
		case 9:PrintfExpertInfo(Connection); break;
		case 10:DelExpert(Connection); break;
		case 11:findExpert(Connection); break;
		case 12:PriintfStatistick(Connection); break;
		case 13:startMenu(Connection); break;
		}
	}
}

void Menu::ExpertMenu(Server& Connection)
{
	while (true)
	{
		char buf[100];
		int ch;
		//displayExpert(Connection);
		cout << endl;
		cout << "1)Добавить вид недвижимости" << endl;
		cout << "2)Дать оценку" << endl;
		//cout << "2)Вывод всей недвижимости " << endl;
		cout << "3)Вывод параметров аккаунта " << endl;
		cout << "4)Редактирование параметров аккаунта " << endl;
		cout << "5)Выход" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addCredit(Connection); break;
		case 2:addRating(Connection); break;
		case 3:displayExpert(Connection); break;
		case 4:MenuChangeExpert(Connection); break;
		case 5:startMenu(Connection);
		}
	}
}

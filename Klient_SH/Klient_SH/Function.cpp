#include "Function.h"

void printfHistory(Server& obj)
{
	system("cls");
	cout << "�������  " << endl;
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		if (ch == -1)
		{
			break;
		}
		else
		{
			char nameCredit[100], buf[100], buf1[100], date[100], status[100];
			int sum, procent;
			recv(obj.getConnetc(), date, sizeof(date), 0);
			recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			procent = atoi(buf);
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "################################" << endl;
			cout << "���� ���������� ��������� : " << date << endl;
			cout << "������������ ������������ : " << nameCredit << endl;
			cout << "������� : " << procent << endl;
			cout << "��������� : " << sum << endl;
		}
	}
}

void printf_money(Server& obj)
{
	cout << "���� ������ ������� >> " << endl;
	cout << "������� ����� : ";
	int sum;
	cin >> sum;
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	int ch = atoi(buf);
	if (ch = -1)
	{
		cout << "� ��� ������������ ������� " << endl;
	}
	else
	{
		cout << "���������� ������ ������� " << endl;
	}
}

void replenih_account(Server& obj)
{
	cout << "���� ���������� ����� >>" << endl;
	cout << "������� ����� ��� ��������� : ";
	int sum;
	cin >> sum;
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "����� ���������� " << endl;
}

void assesmentExpert(Server& obj)
{
	int cher;
	char msg[100];
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cher = atoi(msg);
	if (cher == 1)
	{
		cout << "��� �� ����� ������ ���� �� ������ ���� ������������ !" << endl;
	}
	else
	{

		char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
		int sum, procent;
		recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		procent = atoi(buf);
		recv(obj.getConnetc(), buf1, sizeof(buf1), 0);
		sum = atoi(buf1);
		cout << "������ ������������ (!!!)" << endl;
		cout << "�������� : " << nameCredit << endl;
		cout << "������� : " << procent << endl;
		cout << "��������� : " << sum << endl;
	}
}

void checkImput(int i)
{
	while (true)
	{

		if (!cin)
		{
			cout << "������ ����� ,������� ����� !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;

	}
}

void Repay(Server& obj)
{
	int repay;
	int check;
	int ch;
	char date[100];
	char buf[100], msg[100], che[100];
	recv(obj.getConnetc(), che, sizeof(che), 0);
	ch = atoi(che);
	if (ch == 1)
	{
		cout << "��� ������� ������������ !" << endl;
	}
	else
	{
		cout << "������� ����������� ���� : ";
		cin >> date;
		cout << "������� ����� ������� ������ �������� : ";
		cin >> repay;
		itoa(repay, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		send(obj.getConnetc(), date, sizeof(date), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		check = atoi(msg);
		if (check == 0)
		{
			int sum;
			char buf2[100];
			recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
			sum = atoi(buf2);
			cout << "������� ������������� �� ������� ���������� : " << sum << endl;
		}
		if (check == 1)
		{
			cout << "����������� �������� !" << endl;
		}
		if (check == 2)
		{
			char buf2[100];
			int sum;
			recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
			sum = atoi(buf2);
			cout << "������ ������� � �������� , ����� � ������� = " << sum << " ����� �������� �� ��� ���� !" << endl;
		}
	}
}

void Make_Credit(Server& obj)
{

}

void addCredit(Server& obj)
{
	int check;
	char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
	int sum, procent;
	cout << "���� ���������� ������� >>" << endl;
	cout << "������� �������� ������� : ";
	cin >> nameCredit;
	send(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
	cout << "������� ������� : ";
	cin >> procent;
	itoa(procent, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������� ����� ������� : ";
	cin >> procent;
	itoa(procent, buf1, 10);
	send(obj.getConnetc(), buf1, sizeof(buf1), 0);
	system("cls");
	cout << "������� �������� !" << endl;
	cout << "������������ ������� : " << nameCredit << endl;
	cout << "������� ������� : " << procent << endl;
	system("pause");
	system("cls");
}

void addRating(Server& obj)
{
	PrintfIntoCredit(obj);
	char siz[100];
	int size;
	recv(obj.getConnetc(), siz, sizeof(siz), 0);
	size = atoi(siz);
	if (size == 0)
	{
		cout << "��� ������������ " << endl;
	}
	else
	{
		int rating, b_int, b_int2;
		char buf[100];
		double p;
		cout << "��������� ������(��� ��������� ���������): " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i != j) {
					cout << "��������� Z" << i + 1 << " ��� Z" << j + 1 << "(1 ��� 0): ";
					while (true) {
						cin >> rating;
						checkImput(rating);
						if (rating < 0 || rating > 1) {
							cout << "�� ������ ������, ��������� ������� " << endl;
						}
						else break;
					}
					itoa(rating, buf, 10);
					send(obj.getConnetc(), buf, sizeof(buf), 0);
				}
			}
		}

		cout << endl; for (int k = 0; k <= size; k++) { cout << "+-----"; } cout << "+" << endl;

		for (int i = 0; i < size; i++) {
			if (i != 0) cout << setw(2) << right << "Z" << setw(2) << left << i + 1 << " |";
			else cout << right << setw(5) << "|     " << "| Z1  |";
		}
		cout << endl; for (int k = 0; k <= size; k++) { cout << "+-----"; } cout << "+" << endl;
		for (int i = 0; i < size; i++) {
			cout << right << "| Z" << left << setw(2) << i + 1 << " |";
			for (int j = 0; j < size; j++) {
				recv(obj.getConnetc(), siz, sizeof(siz), 0);
				rating = atoi(siz);
				if (i != j) cout << setw(3) << right << rating << "  |";
				else cout << "  -  |";
			}
			cout << endl; for (int k = 0; k <= size; k++) { cout << "+-----"; } cout << "+" << endl;
		}
		cout << "������� ���� �����(�� ������� ���������): " << endl;
		for (int i = 0; i < size; i++) {
			recv(obj.getConnetc(), siz, sizeof(siz), 0);
			p = atof(siz);
			cout << " Z" << i + 1 << " = " << p << endl;
		}

		cout << "��������� ������(��� ����������������� ���������): " << endl;
		b_int2 = 100;
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				recv(obj.getConnetc(), siz, sizeof(siz), 0);
				b_int = atof(siz);
				cout << " p" << b_int << " = ";
				while (true) {
					cin >> b_int;

					checkImput(b_int);
					if (b_int < 0 || b_int >= b_int2) {
						cout << "�� ������ ������, ��������� �������: ";
					}
					else {
						b_int2 = b_int;
						break;
					}
				}
				itoa(b_int, buf, 10);
				send(obj.getConnetc(), buf, sizeof(buf), 0);
			}
			else {
				recv(obj.getConnetc(), siz, sizeof(siz), 0);
				b_int = atof(siz);
				cout << " p" << b_int << " = 100" << endl;
			}
		}

		cout << "������� ���� �����(�� ����������������� ���������): " << endl;
		for (int i = 0; i < size; i++) {
			recv(obj.getConnetc(), siz, sizeof(siz), 0);
			b_int = atof(siz);

			recv(obj.getConnetc(), siz, sizeof(siz), 0);
			p = atof(siz);
			cout << " Z" << b_int << " = " << p << endl;
		}
		recv(obj.getConnetc(), siz, sizeof(siz), 0);
		rating = atoi(siz);
		cout << "��������� ������������: �" << rating << endl;
	}
}

void addClient(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void addAdmin(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void addExpert(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "��� ������ ������������� " << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� " << name << ":)" << endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "��� ������ ��������������  " << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� ������������� " << name << ":)" << endl;
	}
}

void AutorizationExpert(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "��� ������ ������������� " << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� " << name << ":)" << endl;
	}
}

void PrintfUserInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << "����� �� ����� " << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << cash << endl;
	}
	system("pause");
	system("cls");
}

void PrintfAdminInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfExpertInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfIntoCredit(Server& obj)
{
	system("cls");
	int check;
	char msg[100];
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	check = atoi(msg);
	cout << "� \t" << "������������ ������������ \t" << "������� \t" << "��������� \t" << endl;
	for (int i = 0; i < check; i++)
	{
		char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
		int sum, procent;
		recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		procent = atoi(buf);
		recv(obj.getConnetc(), buf1, sizeof(buf1), 0);
		sum = atoi(buf1);
		cout << i + 1 << "\t" << nameCredit << "\t" << setw(9) << procent << "\t" << setw(19) << sum << "\t" << endl;
	}
	system("pause");
}

void PriintfStatistick(Server& obj)
{
	int che;
	char bue[100];
	recv(obj.getConnetc(), bue, sizeof(bue), 0);
	che = atoi(bue);
	if (che == 1)
	{
		cout << "��������� ��� !" << endl;
	}
	else
	{
		int check;
		char buf[100];
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		check = atoi(buf);
		for (int i = 0; i < check; i++)
		{
			char date[100];
			char nameClient[100];
			char pas_info[100];
			char tel[100], msg[100], bufproc[100], bufsum[100];
			char nameCredit[100];
			int procen;
			int sum;
			recv(obj.getConnetc(), date, sizeof(date), 0);
			recv(obj.getConnetc(), nameClient, sizeof(nameClient), 0);
			recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
			recv(obj.getConnetc(), tel, sizeof(tel), 0);
			recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
			recv(obj.getConnetc(), bufproc, sizeof(bufproc), 0);
			recv(obj.getConnetc(), bufsum, sizeof(bufsum), 0);
			procen = atoi(bufproc);
			sum = atoi(bufsum);
			cout << "###########################################################" << endl;
			cout << "���� ������ ������� :" << date << endl;
			cout << "��� �������� :" << nameClient << endl;
			cout << "���������� ������ ��������:" << pas_info << endl;
			cout << "����� �������� �������� :" << tel << endl;
			cout << "������������ ���� ������� :" << nameCredit << endl;
			cout << "������� ������� :" << procen << endl;
			cout << "����� ������� :" << sum << "���." << endl;

		}
	}
}

void DelClient(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� ������������ " << endl;
	cout << "������� ����� ������������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "��������� �������� : " << cash << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������������� " << endl;
	cout << "������� ����� ������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������� " << endl;
	cout << "������� ����� : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void findClient(Server& obj)
{
	system("cls");
	cout << "���� ������ ������� >>" << endl;
	cout << "������� ����� ������� : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "��������� �������� : " << cash << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findAdmin(Server& obj)
{
	system("cls");
	cout << "���� ������ ������ >>" << endl;
	cout << "������� ����� ������ : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findExpert(Server& obj)
{
	system("cls");
	cout << "���� ������ ��������� >>" << endl;
	cout << "������� ����� �������� : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

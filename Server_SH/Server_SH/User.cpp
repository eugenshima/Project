#include "User.h"


User::User()
{
	FileCreator obj;
	obj.read_vector(FileClient, vecHuman);
	obj.read_vector(FileAdmin, vecAdmin);
	obj.read_vector(FileExpert, vecExpert);
	obj.read_vector(FileStats, vecStats);
	obj.read_vector(FileProduct, vecBank);
	obj.read_vector(FileRating, vecRating);
}

void User::printfHistoryN(int i, Server& obj)
{
	int ch = 0;
	int shect = 0;
	char buf[100];
	for (int j = 0; j < vecStats.size(); j++)
	{
		if (strcmp(vecHuman[i].getName(), vecStats[j].getNameClietn()) == 0 && strcmp(vecHuman[i].getPas_info(), vecStats[j].getPas_info()) == 0)
		{
			itoa(ch, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char date[100];
			char nameClient[100];
			char pas_info[100];
			char tel[100];
			char nameCredit[100];
			char status[100];
			int procen;
			int sum;
			strcpy_s(date, sizeof(date), vecStats[j].getDate());
			strcpy_s(nameCredit, sizeof(nameCredit), vecStats[j].getNameProp());
			procen = vecStats[j].getProcent();
			sum = vecStats[j].getSum();
			send(obj.GetNewConnection(), date, sizeof(date), 0);
			send(obj.GetNewConnection(), nameCredit, sizeof(nameCredit), 0);
			itoa(procen, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			itoa(sum, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		}
		shect++;
		if (shect == vecStats.size())
		{
			int check = -1;
			char mss[100];
			itoa(check, mss, 10);
			send(obj.GetNewConnection(), mss, sizeof(mss), 0);
		}

	}
}

void User::printf_moneyN(int i, Server& obj)
{
	int sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	if (sum > vecHuman[i].getCash())
	{
		int ch = -1;
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
	else
	{
		int ch = 0;
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		vecHuman[i].setCasg(vecHuman[i].getCash() - sum);
		cout << "User - " << vecHuman[i].getName() << "   забрал из своей ячейки на складе товаров на сумму - " << sum << "руб " << endl;
	}
}

void User::replenih_account(Server& obj, int i)
{
	char buf[100];
	int sum;
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	vecHuman[i].setCasg(vecHuman[i].getCash() + sum);
	seve_info_Client();
	cout << "User - " << vecHuman[i].getName() << " положил в свою ячейку на складе товаров на сумму - " << sum << endl;
}

void User::opinionExpert(Server& obj, int i)
{
	int cof = 0;
	char nameExpert[100];
	float rang[100][100];
	if (vecRating.size() == 0 && vecBank.size() == 0) {
		int ch = 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
	else {
		int ch = 0;
		char buf[100];
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		Rating temp;
		for (int i = 0; i < vecRating.size() - 1; i++) {
			for (int j = 0; j < vecRating.size() - i - 1; j++) {
				if (vecRating[j].getPosition() > vecRating[j + 1].getPosition()) {
					temp = vecRating[j];
					vecRating[j] = vecRating[j + 1];
					vecRating[j + 1] = temp;
				}
			}
		}

		float rang[100][100];
		int pet = 0;
		for (int i = 0; i < vecRating.size() / 2; i++) {
			for (int j = 0; j < vecBank.size(); j++) {
				if (pet == vecRating.size())
					break;
				rang[i][j] = vecRating[pet].getRating();
				pet++;
			}
		}

		for (int i = 0; i < vecRating.size() / 2; i++) {
			cout << endl;
			for (int j = 0; j < vecBank.size(); j++)
				cout << rang[i][j];
		}
		cout << endl;

		int masCof[100];
		for (int i = 0; i < vecRating.size() / 2; i++) {
			int cof = 0;
			for (int j = 0; j < vecBank.size(); j++)
				cof = rang[i][j] + cof;
			cout << "kof - " << cof << endl;
			masCof[i] = cof;
		}
		float masAge[100];

		for (int i = 0; i < vecRating.size() / 2; i++) {
			float age = 0;
			for (int j = 0; j < vecBank.size(); j++) {
				float ag = rang[i][j] / masCof[j];
				age = age + ag;
			}
			age = age / (vecRating.size() / 2);
			cout << "age - " << age << endl;
			masAge[i] = age;
		}
		int check = 0;
		float iterator;
		iterator = masAge[0];
		for (int i = 0; i < vecRating.size() / 2; i++) {
			if (iterator < masAge[i]) {
				iterator = masAge[i];
				check = i;
			}
		}
		char nameCredit[100];
		char nameExpert[100];
		char loginExpert[100];
		int procent;
		int sum;
		strcpy_s(nameCredit, sizeof(nameCredit), vecBank[check].getNameProp());
		procent = vecBank[check].getProcent();
		sum = vecBank[check].getSum();
		send(obj.GetNewConnection(), nameCredit, sizeof(nameCredit), 0);
		itoa(procent, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		itoa(sum, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
}

void User::replenish(Server& obj, int i)
{
	int chek = 0;
	int cheks;
	char chakc[100];
	char date[100];
	int sum;
	char buf[100];
	if (vecStats.size() == 0)
	{
		cheks = 1;
		itoa(cheks, chakc, 10);
		send(obj.GetNewConnection(), chakc, sizeof(chakc), 0);
	}
	else
	{
		cheks = 2;
		itoa(cheks, chakc, 10);
		send(obj.GetNewConnection(), chakc, sizeof(chakc), 0);
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		recv(obj.GetNewConnection(), date, sizeof(date), 0);
		sum = atoi(buf);
		for (int j = 0; j < vecStats.size(); j++)
		{
			if (strcmp(vecHuman[i].getPas_info(), vecStats[j].getPas_info()) == 0 && strcmp(vecHuman[i].getTel(), vecStats[j].getTel()) == 0)
			{
				int sum2 = vecStats[j].getSum();
				if (sum < vecStats[j].getSum())
				{
					chek = 0;
					int itog = vecStats[j].getSum() - sum;
					char status[100] = { "Задолжность !" };
					char buf[100];
					itoa(chek, buf, 10);
					send(obj.GetNewConnection(), buf, sizeof(buf), 0);
					itoa(itog, buf, 10);
					send(obj.GetNewConnection(), buf, sizeof(buf), 0);
					Statistick stat;
					ofstream file(FileStatistic, ios::app);
					stat.setSum(sum);
					vecStats[j].setSum(itog);
					stat.setNameClient(vecHuman[i].getName());
					stat.setPas_info(vecHuman[i].getPas_info());
					stat.setTel(vecHuman[i].getTel());
					for (int l = 0; l < vecBank.size(); l++)
					{
						if (strcmp(vecStats[j].getNameProp(), vecBank[l].getNameProp()) == 0)
						{
							stat.setNameProp(vecBank[l].getNameProp());
							stat.setProcent(vecBank[l].getProcent());
						}
					}
					stat.setStatus(status);
					stat.setDate(date);
					file << stat;
					file.close();
					vecHuman[i].setCasg(itog * -1);
					seve_info_Client();
					save_info_Stats();
				}
				if (sum == sum2)
				{
					char status[100] = { "Погашенно !" };
					chek = 1;
					char buf[100];
					itoa(chek, buf, 10);
					send(obj.GetNewConnection(), buf, sizeof(buf), 0);
					ofstream file(FileStatistic, ios::app);
					Statistick stat;
					vecStats[j].setSum(0);
					stat.setNameClient(vecHuman[i].getName());
					stat.setPas_info(vecHuman[i].getPas_info());
					stat.setTel(vecHuman[i].getTel());
					stat.setDate(date);
					for (int l = 0; l < vecBank.size(); l++)
					{
						if (strcmp(vecStats[j].getNameProp(), vecBank[l].getNameProp()) == 0)
						{
							stat.setNameProp(vecBank[l].getNameProp());
							stat.setProcent(vecBank[l].getProcent());
						}
					}
					stat.setStatus(status);
					stat.setSum(sum2);
					vecHuman[i].setCasg(sum - sum);
					file << stat;
					file.close();
					auto res = vecStats.begin();
					vecStats.erase(res + j);
					save_info_Stats();
					seve_info_Client();
				}
				if (sum > sum2)//проблема тут !
				{
					char buf2[100], msg[100];
					char status[100] = { "Погашенно !" };
					chek = 2;
					itoa(chek, buf2, 10);
					send(obj.GetNewConnection(), buf2, sizeof(buf2), 0);
					int itog = sum - vecStats[j].getSum();
					int rezault = sum - sum2;
					char msg2[100];
					itoa(rezault, msg2, 10);
					send(obj.GetNewConnection(), msg2, sizeof(msg2), 0);
					vecHuman[i].setCasg(rezault);
					Statistick stat;
					vecStats[j].setSum(0);
					stat.setNameClient(vecHuman[i].getName());
					stat.setPas_info(vecHuman[i].getPas_info());
					stat.setTel(vecHuman[i].getTel());
					stat.setDate(date);
					stat.setStatus(status);
					stat.setSum(sum2);
					for (int l = 0; l < vecBank.size(); l++)
					{
						if (strcmp(vecStats[j].getNameProp(), vecBank[l].getNameProp()) == 0)
						{
							stat.setNameProp(vecBank[l].getNameProp());
							stat.setProcent(vecBank[l].getProcent());
						}
					}

					ofstream file(FileStatistic);
					file << stat;
					file.close();
					auto res = vecStats.begin();
					vecStats.erase(res + j);
					save_info_Stats();
					seve_info_Client();
				}
			}
		}
	}

}

void User::receptionExpert(int i, Server& obj)
{
	User us;
	char name[100], tel[100], pas_info[100], login[100], password[100];
	strcpy_s(name, sizeof(name), vecExpert[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);

}

void User::reception(int i, Server& obj)
{
	User us;
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	strcpy_s(name, sizeof(name), vecHuman[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
	cash = vecHuman[i].getCash();
	itoa(cash, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
}



int User::AutorizationAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::addClient(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecHuman.push_back(obj1);
	cout << "Новый пользователь был зарегестрирован!" << endl;
}

void User::addAdmin(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecAdmin.push_back(obj1);
	cout << "Новый пользователь был зарегестрирован!" << endl;
}

void User::addExpert(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecExpert.push_back(obj1);
	cout << "Новый Эксперт был зарегестрирован!" << endl;
}

int User::AutorizationClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

int User::AutorizationExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::TakeProp(Server& obj, char* buf, int client)
{
	int check = 0;
	for (int i = 0; i < vecBank.size(); i++)
	{
		if (strcmp(vecBank[i].getNameProp(), buf) == 0)
		{
			Statistick stat;
			char status[100] = { "Задолжность !" };
			char date[100];
			char nameClient[100];
			char pas_info[100];
			char tel[100], msg[100], bufproc[100], bufsum[100];
			char nameCredit[100];
			int procen;
			int sum;
			check++;
			itoa(check, msg, 10);
			send(obj.GetNewConnection(), msg, sizeof(msg), 0);
			recv(obj.GetNewConnection(), date, sizeof(date), 0);
			stat.setDate(date);
			strcpy_s(nameClient, sizeof(nameClient), vecHuman[client].getName());
			stat.setNameClient(nameClient);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[client].getPas_info());
			stat.setPas_info(pas_info);
			strcpy_s(tel, sizeof(tel), vecHuman[client].getTel());
			stat.setTel(tel);
			strcpy_s(nameCredit, sizeof(nameCredit), vecBank[i].getNameProp());
			stat.setStatus(status);
			stat.setNameProp(nameCredit);
			procen = vecBank[i].getProcent();
			stat.setProcent(procen);
			sum = vecBank[i].getSum();
			stat.setSum(sum);
			vecHuman[client].setCasg(vecHuman[i].getCash() - sum);
			vecStats.push_back(stat);
			seve_info_Client();
			save_info_Stats();
			ofstream file;
			file.open(FileStatistic, ios::app);
			file << stat;
			cout << "Было взято товаров со склада клиентом " << nameClient << endl;
			cout << "На сумму :" << sum << endl;
			cout << "Подробности в файле Report" << endl;
		}
	}
	if (check == 0)
	{
		char msg2[100];
		itoa(check, msg2, 10);
		send(obj.GetNewConnection(), msg2, sizeof(msg2), 0);
	}
}

void User::addProp(Server& obj, int i)
{
	char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
	int sum, procent;
	Org credit;
	recv(obj.GetNewConnection(), nameCredit, sizeof(nameCredit), 0);
	credit.setNameProp(nameCredit);
	recv(obj.GetNewConnection(), buf1, sizeof(buf1), 0);
	procent = atoi(buf1);
	credit.setProcent(procent);
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	credit.setSum(sum);
	strcpy_s(nameExpert, sizeof(nameExpert), vecExpert[i].getName());
	credit.setNameExpert(nameExpert);
	strcpy_s(loginExpert, sizeof(loginExpert), vecExpert[i].getlogin());
	credit.setLoginExpert(loginExpert);
	vecBank.push_back(credit);
	save_info_bank();
	cout << "Был добавлне новая недвижимость Экспертом" << nameExpert;
}

void User::addRating(Server& obj, int i)
{
	printf_infoProp(obj);
	int size = vecBank.size();
	char siz[100];
	itoa(size, siz, 10);
	send(obj.GetNewConnection(), siz, sizeof(siz), 0);
	char buf[100];
	if (size == 0) {}
	else
	{
		int** array = new int* [size];
		for (int i = 0; i < size; i++)
			array[i] = new int[size] {0};
		int find = 0, v = 0, flag;
		double* C = new double[size] {0};
		double* p = new double[size] {0};
		double temp;


		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i != j) {
					recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
					array[i][j] = atoi(buf);
					array[j][i] = 1 - array[i][j];
				}
			}
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				itoa(array[i][j], siz, 10);
				send(obj.GetNewConnection(), siz, sizeof(siz), 0);
			}
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				C[i] += array[i][j];
			}
			v += C[i];
		}
		for (int i = 0; i < size; i++) {
			p[i] = C[i] / v;
			sprintf(siz, "%.4f", p[i]);
			send(obj.GetNewConnection(), siz, sizeof(siz), 0);
		}

		int** mas = new int* [size];
		for (int i = 0; i < size; i++) {
			mas[i] = new int[2]{ 0 };
			mas[i][1] = i;
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (p[j] < p[j + 1]) {
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;

					flag = mas[j][1];
					mas[j][1] = mas[j + 1][1];
					mas[j + 1][1] = flag;
				}
			}
		}

		for (int i = 0; i < size; i++) {
			if (i != 0) {
				itoa(mas[i][1] + 1, siz, 10);
				send(obj.GetNewConnection(), siz, sizeof(siz), 0);

				recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
				mas[i][0] = atoi(buf);
				//cin >> mas[i][0];
			}
			else {
				mas[i][0] = 100;
				itoa(mas[i][1] + 1, siz, 10);
				send(obj.GetNewConnection(), siz, sizeof(siz), 0);
			}
		}
		int* mas2 = new int[size - 1]{ 0 };
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				mas2[i] += mas[j][0];

			}
		}
		v = 0;
		for (int i = 0; i < size - 1; i++) {
			if (mas[i][0] <= mas2[i]) {
				mas[i][0] = 20 + mas2[i];
			}
			v += mas[i][0];
		}

		double* p1 = new double[size] {0};
		for (int i = 0; i < size; i++) {

			if (mas[find][0] < mas[i][0]) {
				find = i;
			}
			p1[i] += mas[i][0];
			p1[i] /= v;
			itoa(mas[i][1] + 1, siz, 10);
			send(obj.GetNewConnection(), siz, sizeof(siz), 0);
			sprintf(siz, "%.4f", p1[i]);
			send(obj.GetNewConnection(), siz, sizeof(siz), 0);
		}
		find = mas[find][1] + 1;
		itoa(find, siz, 10);
		send(obj.GetNewConnection(), siz, sizeof(siz), 0);

		Rating rat;
		char nameExpert[100];
		strcpy_s(nameExpert, sizeof(nameExpert), vecExpert[i].getName());
		for (int i = 0; i < size; i++) {
			rat.setNameExpert(nameExpert);
			rat.setRating(mas[i][0]);
			rat.setPosition(mas[i][1] + 1);
			int k = 0;
			if (vecRating.size() > 0) {
				for (int i = 0; i < vecRating.size(); i++) {
					if (strcmp(vecRating[i].getNameExpert(), rat.getNameExpert()) == 0 && vecRating[i].getPosition() == rat.getPosition()) {
						vecRating[i] = rat;
						k = 1;
						break;
					}
				}
			}
			if (k == 0)
				vecRating.push_back(rat);
		}
		for (int i = 0; i < size; i++) delete[] array[i];
		for (int i = 0; i < size; i++) delete[] mas[i];
		delete[] array; delete[] C; delete[] p; delete[] p1;  delete[] mas; delete[] mas2;
		save_info_Rating();
	}

}

void User::delClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			char msg[100];
			float cash = vecHuman[i].getCash();
			itoa(cash, msg, 10);
			send(obj.GetNewConnection(), msg, sizeof(msg), 0);
			auto res = vecHuman.begin();
			vecHuman.erase(res + i);
			seve_info_Client();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}

}

void User::delAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecAdmin.begin();
			vecAdmin.erase(res + i);
			save_info_Admin();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::delExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecExpert.begin();
			vecExpert.erase(res + i);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findUser(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			char msg[100];
			float cash = vecHuman[i].getCash();
			itoa(cash, msg, 10);
			send(obj.GetNewConnection(), msg, sizeof(msg), 0);
			seve_info_Client();
			break;
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findAdmin(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Admin();
			break;
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findExpert(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::PrintfStatistick(Server& obj)
{
	int che;
	char bue[100];
	if (vecStats.size() == 0)
	{
		che = 1;
		itoa(che, bue, 10);
		send(obj.GetNewConnection(), bue, sizeof(bue), 0);
	}
	else
	{
		che = 0;
		itoa(che, bue, 10);
		send(obj.GetNewConnection(), bue, sizeof(bue), 0);
		int check = vecStats.size();
		char buf[100];
		itoa(check, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		for (int i = 0; i < vecStats.size(); i++)
		{
			char date[100];
			char nameClient[100];
			char pas_info[100];
			char tel[100], msg[100], bufproc[100], bufsum[100];
			char nameCredit[100];
			int procen;
			int sum;
			strcpy_s(date, sizeof(date), vecStats[i].getDate());
			strcpy_s(nameClient, sizeof(nameClient), vecStats[i].getNameClietn());
			strcpy_s(pas_info, sizeof(pas_info), vecStats[i].getPas_info());
			strcpy_s(tel, sizeof(tel), vecStats[i].getTel());
			strcpy_s(nameCredit, sizeof(nameCredit), vecStats[i].getNameProp());
			procen = vecStats[i].getProcent();
			itoa(procen, bufproc, 10);
			sum = vecStats[i].getSum();
			itoa(sum, bufsum, 10);
			send(obj.GetNewConnection(), date, sizeof(date), 0);
			send(obj.GetNewConnection(), nameClient, sizeof(nameClient), 0);
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			send(obj.GetNewConnection(), nameCredit, sizeof(nameCredit), 0);
			send(obj.GetNewConnection(), bufproc, sizeof(bufproc), 0);
			send(obj.GetNewConnection(), bufsum, sizeof(bufsum), 0);


		}
	}
}

void User::printf_infoProp(Server& obj)
{
	int check = vecBank.size();
	char msg[100];
	itoa(check, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	for (int i = 0; i < vecBank.size(); i++)
	{
		char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
		int sum, procent;
		strcpy_s(nameCredit, sizeof(nameCredit), vecBank[i].getNameProp());
		send(obj.GetNewConnection(), nameCredit, sizeof(nameCredit), 0);
		procent = vecBank[i].getProcent();
		itoa(procent, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		sum = vecBank[i].getSum();
		itoa(sum, buf1, 10);
		send(obj.GetNewConnection(), buf1, sizeof(buf1), 0);
	}

}


void User::printf_infoClient(Server& obj)
{
	char buf[100];
	int size;
	size = vecHuman.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
		char msg[100];
		cash = vecHuman[i].getCash();
		itoa(cash, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
}

void User::printf_infoAdmin(Server& obj)
{
	char buf[100];
	int size;
	size = vecAdmin.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecAdmin[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::printf_infoExpert(Server& obj)
{
	char buf[100];
	int size;
	size = vecExpert.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecExpert[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::save_info_Stats()
{
	FileCreator obj;
	obj.write_vector_Statistick(vecStats);
}

void User::save_info_bank()
{
	FileCreator obj;
	obj.write_vector_Bank(vecBank);
}


void User::seve_info_Client()
{
	FileCreator obj;
	obj.write_vector_User(vecHuman);
}

void User::save_info_Admin()
{
	FileCreator obj;
	obj.write_vector_Admin(vecAdmin);
}

void User::save_info_Expert()
{
	FileCreator obj;
	obj.write_vector_Expert(vecExpert);
}

void User::save_info_Rating()
{
	FileCreator file;
	file.write_vector_Rating(vecRating);
}

User::~User()
{

}


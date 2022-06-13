#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Statistick
{
	char date[100];
	char nameClient[100];
	char pas_info[100];
	char tel[100];
	char nameProp[100];
	char status[100];
	int procen;
	int sum;
public:
	void setStatus(char* a);
	char* getStatus();
	void setDate(char* a);
	void setNameClient(char* a);
	void setPas_info(char* a);
	void setTel(char* a);
	void setNameProp(char* a);
	void setProcent(int a);
	void setSum(int a);
	char* getDate();
	char* getNameClietn();
	char* getPas_info();
	char* getTel();
	char* getNameProp();
	int getProcent();
	int getSum();
	friend ostream& operator<<(ostream& os, Statistick& obj);
	friend istream& operator>>(istream& os, Statistick& obj);
};


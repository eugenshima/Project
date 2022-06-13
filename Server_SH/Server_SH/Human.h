
#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Human
{
protected:
	char name[100];
	char tel[100];
	char pas_indo[100];
	char password[100];
	char login[100];
	float cash;
	float contribution;
public:
	Human();
	Human(int a);
	void setName(char* nam);
	void setTel(char* tel);
	void setPass_info(char* info);
	void setPassword(char* pass);
	void setLogin(char* log);
	void setCasg(float s);
	float getCash();
	float getContribution();
	char* getName();
	char* getTel();
	char* getPas_info();
	char* getlogin();
	char* getPassword();
	friend ostream& operator<<(ostream& os, Human& obj);
	friend istream& operator>>(istream& os, Human& obj);
};


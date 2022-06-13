#pragma once
#include<iostream>
#include<string>
#include<WinSock2.h>
using namespace std;
class Client
{
	string login;
	string password;
	string name;
	string secondName;
	string patrinicName;
	string pas_info;
	string tel;
	float cash;
	float countribution;
public:
	void setLogin(string log);
	void setPassword(string pas);
	void setName(string nam);
	void setSecondName(string srcond);
	void setPatronicName(string pat);
	void setPas_info(string inf);
	void setTel(string t);
	void setCash(float a);
	void setCountribution();
	string getLogin();
	string getPassword();
	string getName();
	string getSecondName();
	string getPatronicName();
	string getPas_info();
	string getTel();
	float getCash();
	float getCountribution();

};

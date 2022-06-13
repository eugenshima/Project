#include "Bank.h"

void Org::setNameProp(char* name)
{
	strcpy_s(nameCredit, sizeof(nameCredit), name);
}

void Org::setNameExpert(char* name)
{
	strcpy_s(nameExpert, sizeof(nameExpert), name);
}

void Org::setLoginExpert(char* name)
{
	strcpy_s(loginExpert, sizeof(loginExpert), name);
}

void Org::setProcent(int a)
{
	procent = a;
}

void Org::setSum(int a)
{
	sum = a;
}

char* Org::getNameProp()
{
	return nameCredit;
}

char* Org::getNameExpert()
{
	return nameExpert;
}

char* Org::getLoginExpert()
{
	return loginExpert;
}

int Org::getProcent()
{
	return procent;
}

int Org::getSum()
{
	return sum;
}

istream& operator>>(istream& os, Org& obj)
{
	os >> obj.nameCredit >> obj.procent >> obj.sum >> obj.nameExpert >> obj.loginExpert;
	return os;
}

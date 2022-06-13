#include "Statistick.h"

void Statistick::setStatus(char* a)
{
	strcpy_s(status, sizeof(status), a);
}

char* Statistick::getStatus()
{
	return status;
}

void Statistick::setDate(char* a)
{
	strcpy_s(date, sizeof(date), a);
}

void Statistick::setNameClient(char* a)
{
	strcpy_s(nameClient, sizeof(nameClient), a);
}

void Statistick::setPas_info(char* a)
{
	strcpy_s(pas_info, sizeof(pas_info), a);
}

void Statistick::setTel(char* a)
{
	strcpy_s(tel, sizeof(tel), a);
}

void Statistick::setNameProp(char* a)
{
	strcpy_s(nameProp, sizeof(nameProp), a);
}

void Statistick::setProcent(int a)
{
	procen = a;
}

void Statistick::setSum(int a)
{
	sum = a;
}

char* Statistick::getDate()
{
	return date;
}

char* Statistick::getNameClietn()
{
	return nameClient;
}

char* Statistick::getPas_info()
{
	return pas_info;
}

char* Statistick::getTel()
{
	return tel;
}

char* Statistick::getNameProp()
{
	return nameProp;
}

int Statistick::getProcent()
{
	return procen;
}

int Statistick::getSum()
{
	return sum;
}

ostream& operator<<(ostream& os, Statistick& obj)
{
	os << "###########################################################" << endl;
	os << "Дата использования склада клиентом :" << obj.getDate() << endl;
	os << "Имя заемщика :" << obj.getNameClietn() << endl;
	os << "Паспортные данные заемщика:" << obj.getPas_info() << endl;
	os << "Номер телефона заемщика :" << obj.getTel() << endl;
	os << "Наименование вида вида ресурса :" << obj.getNameProp() << endl;
	os << "Процент за хранение :" << obj.getProcent() << endl;
	os << "Сумма хранения:" << obj.getSum() << "руб." << endl;
	os << "Статус : " << obj.getStatus() << endl;
	return os;
}

istream& operator>>(istream& os, Statistick& obj)
{
	os >> obj.date >> obj.nameClient >> obj.pas_info >> obj.tel >> obj.nameProp >> obj.procen >> obj.sum;
	return os;
}

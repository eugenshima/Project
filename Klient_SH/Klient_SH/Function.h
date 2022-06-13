#pragma once
#include<iostream>
#include<iomanip>
#include"Server.h"
#include"Menu.h"
using namespace std;
void printfHistory(Server& obj);
void printf_money(Server& obj);
void  replenih_account(Server& obj);
void assesmentExpert(Server& obj);
void checkImput(int i);
void Repay(Server& obj);
void Make_Credit(Server& obj);
void addCredit(Server& obj);
void addRating(Server& obj);
void addClient(Server& obj);
void addAdmin(Server& obj);
void addExpert(Server& obj);
void AutorizationUser(Server& obj);
void AutorizationAdmin(Server& obj);
void AutorizationExpert(Server& obj);
void PrintfUserInfo(Server& obj);
void PrintfAdminInfo(Server& obj);
void PrintfExpertInfo(Server& obj);
void PrintfIntoCredit(Server& obj);
void PriintfStatistick(Server& obj);
void DelAdmin(Server& obj);
void DelClient(Server& obj);
void DelExpert(Server& obj);
void findClient(Server& obj);
void findAdmin(Server& obj);
void findExpert(Server& obj);

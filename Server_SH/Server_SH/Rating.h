#pragma once
#include<iostream>
using namespace std;
class Rating
{
	int rating;
	int position;
	char nameExpert[100];
public:
	void setRating(int a) { rating = a; }
	void setPosition(int a) { position = a; }
	void setNameExpert(char* a) { strcpy_s(nameExpert, sizeof(nameExpert), a); }
	int getRating() { return rating; }
	int getPosition() { return position; }
	char* getNameExpert() { return nameExpert; }
	friend istream& operator>>(istream& os, Rating& obj)
	{
		os >> obj.rating >> obj.nameExpert >> obj.position;
		return os;
	}
};



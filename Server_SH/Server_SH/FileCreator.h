#pragma once
#include"User.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Rating.h"
static string FileClient = "klient.txt";
static string FileAdmin = "Admin.txt";
static string FileProduct = "Product_info.txt";
static string FileExpert = "Expert_info.txt";
static string FileStatistic = "Report.txt";
static string FileStats = "statistick.txt";
static string FileRating = "Rating.txt";
using namespace std;
class FileCreator
{
public:
	template<class T>
	void read_vector(string nameFilem, vector<T>& vec);
	void write_vector_User(vector<Human>& vec);
	void write_vector_Admin(vector<Human>& vec);
	void write_vector_Bank(vector<Org>& vec);
	void write_vector_Expert(vector<Human>& vec);
	void write_vector_Statistick(vector<Statistick>& vec);
	void write_vector_Rating(vector<Rating>& vec);
};

template<class T>
inline void FileCreator::read_vector(string nameFilem, vector<T>& vec)
{
	ifstream file;
	file.open(nameFilem);
	try
	{
		if (file.peek() == EOF)
		{
		}
		else
		{
			while (!file.eof())
			{
				T obj;
				file >> obj;
				vec.push_back(obj);
			}
		}
		file.close();
	}
	catch (const std::exception& ox)
	{
		cout << ox.what() << endl;
		cout << "Ошибка открытия файла :" << nameFilem << endl;
	}
}


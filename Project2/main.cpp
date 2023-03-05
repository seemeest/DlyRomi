#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h> 
using namespace std;


struct Product
{
	string name;
	int price;
	int quantity;
	Product(string name , int price , int quantity) {
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}
	int sum() {
		return price * quantity;
	}
	void print() {
		cout << name << " " << price << " " << quantity << endl;
	}

};

int main() {

	const  int sum = 1000000;
	vector< Product> product;
	
	string content;
	ifstream openfile("input.txt");

	string name;
	int price;
	int quantity;

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Rus"); // ѕодключение русского €зыка

	int i = 0;
	if (openfile.is_open())
	{
		while (getline(openfile, content))
		{
			
			if (i == 0) {
				name = content;
			}
			if (i == 1) {
				price= stoi(content);
			}
			if (i == 2) {
				quantity = stoi(content);

				product.push_back(Product(name, price, quantity));
				i = 0;
			}
			else {
				i++;
			}
		}

	}
	else {
		cout << "error" << endl;
	}

	for (Product product : product) {

		if(product.sum()>= sum)
		product.print();
	}
}
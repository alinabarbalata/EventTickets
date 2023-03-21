#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Person.h";
using namespace std;

void main() {
	//Tester for Birthday class
	Birthday b1(1, 3, 2003);
	cout << b1.getDay() << "." << b1.getMonth() << "." << b1.getYear()<<endl;//works
	//Birthday b2(-1, 12, 2003);//does not work because variable day does not verify condition
	//Birthday b3(1, 15, 2003);//does not work because variable month does not verify condition
	//Birthday b4(1, 12, 2006);//does not work because variable year does not verify condition
	cout << b1.getBirthday_string()<<endl;

	//Tester for Person class
	Person p1("Andreea", "Alexandra", 1, 3, 2002);
	cout<<p1.getBirthday()<<endl;
	cout << p1.getFullName()<<endl;
}
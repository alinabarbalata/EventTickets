#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Person.h";
#include "Exception.h";
using namespace std;

void main() {
	//Tester for Birthday class
	Birthday b1(1, 3, 2003);
	cout << b1.getDay() << "." << b1.getMonth() << "." << b1.getYear()<<endl;//works
	try { 
		Birthday b2(-1, 12, 2003);//does not work because variable day does not verify condition
	}
	catch (CustomException* ex) {
		cout << endl << ex->what();
		delete ex;
	}
	//Birthday b3(1, 15, 2003);//does not work because variable month does not verify condition
	//Birthday b4(1, 12, 2006);//does not work because variable year does not verify condition
	cout << b1.getBirthday_string()<<endl;

	//Tester for Person class
	Person p1("Andreea", "Alexandra", 1, 3, 2002);
	cout<<p1.getBirthday()<<endl;
	cout << p1.getFullName()<<endl;
	p1.printInfo();

	//Tester for ostream operator implementation
	cout << p1;

	//Tester for constructor with phone number parameter
	Person p2("Alina", "X", "0745670009", 6, 8, 2003);
	p2.printInfo();
	//Person p3("Alexandru", "Y", "054598498989", 5, 4, 2000);//phone number is too long

}
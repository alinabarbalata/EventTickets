#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include "Exception.h"
#include "Date.h"
using namespace std;

class Person {
	int idPerson;
	string first_name;
	string last_name;
	Birthday dateOfBirth;
	char phoneNumber[11]="";
public:
	static int COUNTER;
	static int SIZE;
public:
	Person(string first_name, string last_name, int day_birth, int month_birth, int year_birth):first_name(first_name),last_name(last_name) {
		this->dateOfBirth = Birthday(day_birth, month_birth, year_birth);
		COUNTER++;
		this->idPerson = COUNTER;
		this->setPhoneNumber("-");
	}
	Person(string first_name, string last_name, const char* phoneNumber, int day_birth, int month_birth, int year_birth) :first_name(first_name), last_name(last_name){
		this->dateOfBirth = Birthday(day_birth, month_birth, year_birth);
		COUNTER++;
		this->idPerson = COUNTER;
		this->setPhoneNumber("-");
		this->setPhoneNumber(phoneNumber);

	}
	string getFullName() {
		return this->first_name+" "+last_name;
	}
	string getBirthday() {
		return this->dateOfBirth.getDate_string();
	}
	~Person() {
		COUNTER--;
	}
	int getId() {
		return this->idPerson;
	}
	void setPhoneNumber(const char* phoneNumber) {
		if (strlen(phoneNumber) != SIZE && phoneNumber!="-")
			throw new CustomException("Phone number is not the correct size");
		strcpy(this->phoneNumber, phoneNumber);
	}
	char* getPhoneNumber() {
		return this->phoneNumber;
	}
	void printInfo() {
		cout << endl << "Id: " << this->idPerson;
		cout << endl << "Full name: " << this->first_name<<" "<<this->last_name;
		cout << endl << "Birthday: " << this->dateOfBirth.getDate_string();
		cout << endl << "Phone number: " << this->phoneNumber;
		cout << endl;
	}
};
ostream& operator<<(ostream& out,Person& person) {
	out << endl << "Id: " << person.getId();
	out << endl << "Full name: " << person.getFullName();
	out << endl << "Birthday: " << person.getBirthday();
	out << endl << "Phone Number: " << person.getPhoneNumber();
	out << endl;
	return out;
}
int Person::COUNTER = 0;
int Person::SIZE = 10;

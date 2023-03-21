#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include "Exception.h"
using namespace std;

class Birthday {
	int day;
	int month;
	int year;
public:
	Birthday() {
		this->day = 1;
		this->month = 1;
		this->year = getCurrentYear() - 18;
	}
	Birthday(int day, int month, int year) {
		setDay(day);
		setMonth(month);
		setYear(year);
	}
	void setDay(int day) {
		if (day < 1 || day>32) {
			throw new CustomException ("Invalid day!");
		}
		this->day = day;
	}
	void setMonth(int month) {
		if (month < 1 || month>12) {
			throw new CustomException("Invalid month!");
		}
		this->month = month;
	}
	void setYear(int year) {
		if (year > (getCurrentYear() - 18) || year < (getCurrentYear() - 100)) {
			throw new CustomException("Invalid year!");
		}
		this->year = year;
	}
	int getDay() {
		return this->day;
	}
	int getMonth() {
		return this->month;
	}
	int getYear() {
		return this->year;
	}
	string getBirthday_string() {
		return to_string(this->day) + "-" + to_string(this->month) + "-" + to_string(this->year);
	}

	static int getCurrentYear() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		return (1900 + ltm->tm_year);
	}
	/*static string intToString(int int_var) {
		stringstream stream;
		stream >> int_var;
		string string_var;
		stream << string_var;
	}*/

};
class Person {
	int idPerson;
	string first_name;
	string last_name;
	Birthday dateOfBirth;
public:
	static int COUNTER;
public:
	Person(string first_name, string last_name, int day_birth, int month_birth, int year_birth):first_name(first_name),last_name(last_name) {
		this->dateOfBirth = Birthday(day_birth, month_birth, year_birth);
		COUNTER++;
		this->idPerson = COUNTER;
	}
	string getFullName() {
		return this->first_name+" "+last_name;
	}
	string getBirthday() {
		return this->dateOfBirth.getBirthday_string();
	}
	~Person() {
		COUNTER--;
	}
	int getId() {
		return this->idPerson;
	}
};
int Person::COUNTER = 0;

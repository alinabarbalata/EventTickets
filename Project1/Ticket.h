#pragma once
#include <iostream>
#include <String>
#include "Person.h";
#include <cctype>
using namespace std;

enum TicketType {A,B,C,VIP};
class Ticket {
	char* idTicket = nullptr;
	Person person;
	string namePerson;
	EventDate date;
	char time[6] = "-";
	TicketType type;
public:
	static int COUNTER;
	static int MIN_CHAR;
	static int MAX_CHAR;
public:
	Ticket(Person person, const char* time,int day,int month, int year,TicketType type) {
		this->person = person;
		idGenerator(person.Person::getId(), type);
		setTime(time);
		setName(person.Person::getFullName());
		this->date=EventDate(day, month, year);
		setType(type);
		COUNTER += 10;
	}
	char* idGenerator(int idPerson, TicketType type) {
		int COUNTER_length = countDigits(Ticket::COUNTER);//n=2
		int copy_COUNTER_length = COUNTER_length;
		int copy_COUNTER = Ticket::COUNTER;
		int* COUNTER_digits = nullptr;
		COUNTER_digits = new int[COUNTER_length];
		while (copy_COUNTER) {
			COUNTER_digits[copy_COUNTER_length-1] = copy_COUNTER % 10;//array[1]=0,array[0]=2
			copy_COUNTER /= 10;
			copy_COUNTER_length--;//n=1,n=0
		}//insertion of COUNTER's digits into an array

		//idPerson=5, COUNTER=20, type=VIP
		//id=520*
		int idPerson_length = countDigits(idPerson);
		int copy_idPerson_length = idPerson_length;
		int copyIdPerson = idPerson;
		int* idPerson_digits = nullptr;
		idPerson_digits = new int[idPerson_length];
		while (copyIdPerson) {
			idPerson_digits[copy_idPerson_length - 1] = copyIdPerson % 10;//array[1]=0,array[0]=2
			copyIdPerson /= 10;
			copy_idPerson_length--;//n=1,n=0
		}//insertion of idPerson's digits into an array

		delete[] this->idTicket;
		this->idTicket = new char[idPerson_length + COUNTER_length + 1];//1+2+1=4
		
		//Insertion of idPerson characters
		int i = 0;
		while (i < idPerson_length) {
			this->idTicket[i] = intToChar(idPerson_digits[i]);
			i++;
		}
		i = idPerson_length;
		int j = 0;

		while (i < (COUNTER_length+idPerson_length) && j < COUNTER_length) {
			this->idTicket[i] = intToChar(COUNTER_digits[j]);
			i++;
			j++;
		}
		if (type == VIP) {
			this->idTicket[idPerson_length + COUNTER_length] = '*';
		}
		else
			this->idTicket[idPerson_length + COUNTER_length] = intToChar(type);

		this->idTicket[idPerson_length+COUNTER_length+1] = '\0';
		return this->idTicket;
	}

	static char intToChar(int value) {
		string t = to_string(value);
		char const* n_char = t.c_str();
		return *n_char;
	}

	static int countDigits(int smth) {
		int n = 0;
		while (smth) {
			n++;
			smth = smth / 10;
		}
		return n;
	}

	void setTime(const char* time) {//"08:20"
		if (strlen(time) != 5)
			throw new CustomException("Invalid length for time!");
		int i = 0;
		while (i < strlen(time)) {
			if (i == 2) {
				if (time[i] != ':')
					throw new CustomException("Invalid time format!");
			}
			else
			if (i != 2) {
				if (isdigit(time[i]) == 0)
					throw new CustomException("Invalid time format!");
			}
			i++;
		}
		strcpy(this->time, time);
	}

	void setName(string namePerson) {
		if (countStringCharacters(namePerson) < MIN_CHAR || countStringCharacters(namePerson) > MAX_CHAR)
			throw new CustomException("Invalid name size.");
		this->namePerson = namePerson;
	}

	void setType(TicketType type) {
		this->type = type;
	}
	static int countStringCharacters(string string) {
		int count = 0;
		for (int i = 0; i < string.size(); i++)
			count++;
		return count;
	}

	string getName() {
		return this->namePerson;
	}
	EventDate getDate() {
		return this->date;
	}
	char* getId() {
		char* copy = new char[strlen(this->idTicket) + 1];
		strcpy(copy, idTicket);
		return copy;
	}
	char* getTime() {
		return this->time;
	}
	string getType() {
		string result;
		switch (type) {
		case 0:
			result = "A";
			break;
		case 1:
			result = "B";
			break;
		case 2:
			result = "C";
			break;
		case 3:
			result = "VIP";
			break;
		}
		return result;
	}
};
int Ticket::COUNTER = 10;
int Ticket::MIN_CHAR = 3;
int Ticket::MAX_CHAR = 20;
ostream& operator<<(ostream& out, Ticket ticket) {
	out << endl;
	out << endl << "Id ticket: " << ticket.getId();
	out << endl << "Name Person: " << ticket.getName();
	out << endl << "Ticket Type: " << ticket.getType();
	out << endl << "Date event: " << ticket.getDate();
	out << endl << "Time event: " << ticket.getTime();
	return out;
}

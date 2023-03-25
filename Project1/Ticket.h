#pragma once
#include <iostream>
#include <String>
#include "Person.h";
using namespace std;

enum TicketType {A,B,C,VIP};
class Ticket {
	char* idTicket = nullptr;
	char* namePerson = nullptr;

public:
	static int COUNTER;
public:
	Ticket(int smth) {
		
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
};
int Ticket::COUNTER = 10;

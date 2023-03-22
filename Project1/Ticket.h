#pragma once
#include <iostream>
#include <String>
using namespace std;

enum TicketType {A,B,C,VIP};
class Ticket {
	char* idTicket = nullptr;
public:
	static int COUNTER;
public:
	void idGenerator(int* idPerson, int idPerson_length, TicketType type) {
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
		delete[] this->idTicket;
		this->idTicket = new char[idPerson_length + COUNTER_length + 1 + 1];//1+2+1+1=5

		//Insertion of idPerson characters
		for (int i = 0; i < idPerson_length; i++) {
			this->idTicket[i] = intToChar(idPerson[i]);//added int as char into attribute idTicket
		}//idTicket[0]=5
		int i = idPerson_length;
		int j = 0;
		//~~~~~~~~~~~~~~~~~~~//
		/*while(i<COUNTER_length && j<)
		for (int i = idPerson_length; i < COUNTER_length; i++) {
			this->idTicket[i]=intToChar(COUNTER)
		}*/
	}

	static char intToChar(int value) {
		string t = to_string(value);
		char const* n_char = t.c_str();
		cout << n_char;
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

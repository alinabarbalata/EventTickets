#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Person.h";
#include "Exception.h";
#include "Ticket.h";
#include "Date.h";
#include "Event.h";
using namespace std;

void main() {
	//Tester for Birthday class
	BirthDate b1(1, 3, 2003);
	cout << b1.getDay() << "." << b1.getMonth() << "." << b1.getYear()<<endl;//works
	try { 
		BirthDate b2(-1, 12, 2003);//does not work because variable day does not verify condition
	}
	catch (CustomException* ex) {
		cout << endl << ex->what();
		delete ex;
	}
	//Birthday b3(1, 15, 2003);//does not work because variable month does not verify condition
	//Birthday b4(1, 12, 2006);//does not work because variable year does not verify condition
	cout << b1.getDate_string()<<endl;

	//Tester for Person class
	Person p1("Andreea", "Alexandra", 1, 3, 2002);
	cout<<p1.getBirthDate()<<endl;
	cout << p1.getFullName()<<endl;
	p1.printInfo();

	//Tester for ostream operator implementation
	cout << p1;

	//Tester for constructor with phone number parameter
	Person p2("Alina", "X", "0745670009", 6, 8, 2003);
	p2.printInfo();
	//Person p3("Alexandru", "Y", "054598498989", 5, 4, 2000);//phone number is too long

	//Tester for Ticket class
	/*Ticket t1(1);
	cout<<t1.idGenerator(140, VIP);*/

	//Tester for setTime
	//Ticket t2("08:20");//works
	//Ticket t3("0a:20");//does not work
	//Ticket t4("01020");//does not work
	//Ticket t5("08:200");//does not work
	//Ticket t6(120,"Gabriela Valentin", "08:20",1,2,2023,VIP);//works
	//Ticket t7("Gabriela Valentinnnnnnnnnnnnnnnnnnn", "08:20");//does not work
	//cout <<endl<< t6.getName() << " "<<t6.getDate()<<" "<<t6.getId()<<" "<<t6.getTime()<<endl;
	//cout << t6;

	Ticket t7(p1, "13:20", 20, 7, 2023, VIP);
	cout << t7;

	Person p10("Alexandru", "Radu", 23, 1, 2000);
	Ticket t10(p10, "15:00", 6, 4, 2024, VIP);

	cout << t10;

	int numberSeats[] = {60,70};
	float prices[] = { 150,200 };
	TicketType zones[] = { A,B};
	string name = "name";
	char location[] = "Bucharest no 22";
	Event e1(name,2,numberSeats,prices,location,zones,Movie);
	cout << endl << e1.getLocation()<<" "<<e1.getType();//works
	try {
		e1.setEverthingZonesRelated(2, numberSeats, prices, zones);
	}
	catch (CustomException* ex2) {
		cout << endl << ex2->what();
		delete ex2;
	}
	for (int i = 0; i < 2; i++) {
		cout << e1.getNoSeatsPerZone()[i] << " ";
		cout << e1.getZones()[i] << " ";
		cout << e1.getPricePerZone()[i] << " ";
	}
	
	//int numberSeats2[] = {100,50};
	//float prices2[] = { 200,210 };
	//TicketType zones2[] = { A,VIP };
	//string name2 = "NAMEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
	//char location2[] = "Bucharest";
	//try {
	//	Event e2(name2, 2, numberSeats2, prices2, location2, zones2, Football);//invalid name length
	//}
	//catch (CustomException* ex3) {
	//	cout << endl << ex3->what();
	//	delete ex3;
	//}
	
	int numberSeats2[] = { 100,50 };
	float prices2[] = { 200,210 };
	TicketType zones2[] = { A,VIP };
	string name2 = "NAME";
	char location2[] = "B";
	try {
		Event e2(name2, 2, numberSeats2, prices2, location2, zones2, Football);//invalid location length
	}
	catch (CustomException* ex3) {
		cout << endl << ex3->what();
		delete ex3;
	}
	string nameEvent3 = "Harry Styles: On Tour";
	TicketType zones3[] = { A,B,C,VIP };
	float prices3[] = { 150,342,450,1200 };
	int numberSeats3[] = { 3000,4200,4000,200 };
	char location3[] = "Bucharest National Arena";
	Event e3(nameEvent3, 4, numberSeats3, prices3, location3, zones3, Concert);
	cout << endl << e1.getIdEvent();
	cout << e1 << e3;;

	e1 += 100;
	for (int i = 0; i < e1.getNoZones(); i++)
		cout << e1.getPricePerZone()[i]<<" ";

	cout << "\ne1 seats: " << e1.getTotalSeats() << "\ne3 seats: " << e3.getTotalSeats();
	if (e1 < e3)
		cout << "\ne1 has less seats than e3";
	if (e1 > e3)
		cout << "\ne1 has more seats than e3";
	if (e1 <= e3)
		cout << "\ne1 has less or as many seats as e3";
	if (e1 >= e3)
		cout << "\ne1 has more or as many seats as e3";
	if (e1 == e3)
		cout << "\ne1 has as many seats as e3";
	if (e1 != e3)
		cout << "\ne1 has a different number of seats than e3";

	cout << "\ne1 Prices before: ";
	for (int i = 0; i < e1.getNoZones(); i++)
		cout<<e1.getPricePerZone()[i] << " ";
	cout << "\ne3 Prices before: ";
	for (int i = 0; i < e3.getNoZones(); i++)
		cout << e3.getPricePerZone()[i] << " ";
	e3=e1 + 120;
	cout << "\ne1 Prices after: ";
	for (int i = 0; i < e1.getNoZones(); i++)
		cout << e1.getPricePerZone()[i] << " ";
	cout << "\ne3 Prices after: ";
	for (int i = 0; i < e3.getNoZones(); i++)
		cout << e3.getPricePerZone()[i] << " ";


}
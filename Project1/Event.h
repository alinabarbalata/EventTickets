#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
#include "Ticket.h";

using namespace std;

enum EventType { Movie, Football, Concert, Other };
class Event {
	string nameEvent = "-";
	int* noSeatsPerZone = nullptr;
	TicketType* zones = nullptr;
	int noZones = 0;
	EventType type;
	char* location = nullptr;
	float* pricePerZone = nullptr;
public:
	const static int MIN_CHAR = 3;
	const static int MAX_CHAR = 50;
	const static TicketType array[5];
	const static int MIN_ZONES = 1;
	const static int MAX_ZONES = 4;
	const static float MIN_PRICE;
	const static float MAX_PRICE;
	const static int MIN_SEATS_PER_ZONE = 50;
	const static int MAX_SEATS_PER_ZONE = 100;
private:
	static int NO_EVENTS_CREATED;
public:
	Event(string nameEvent,int noZones,int* noSeatsPerZone,float* pricePerZone,char* location,TicketType* zones,EventType type) {
		setEverthingZonesRelated(noZones, noSeatsPerZone, pricePerZone, zones);
		setName(nameEvent);
		setLocation(location);
		setType(type);
	}
	void setEverthingZonesRelated(int noZones, int* noSeatsPerZone, float* pricePerZone, TicketType* zones) {
		if (noZones<MIN_ZONES || noZones>MAX_ZONES)
			throw new CustomException("Invalid number of zones.");
		this->noZones = noZones;

		delete[] this->noSeatsPerZone, delete[] this->pricePerZone, delete[] this->zones;

		this->noSeatsPerZone = new int[this->noZones];
		this->pricePerZone = new float[this->noZones];
		this->zones = new TicketType[this->noZones];

		for (int i = 0; i < this->noZones; i++) {
			if (noSeatsPerZone[i]<MIN_SEATS_PER_ZONE || noSeatsPerZone[i]>MAX_SEATS_PER_ZONE)
				throw new CustomException("Invalid number of seats per zone");
			else {
				this->noSeatsPerZone[i] = noSeatsPerZone[i];
			}
			if (pricePerZone[i]<MIN_PRICE || pricePerZone[i]>MAX_PRICE)
				throw new CustomException("Invalid prices");
			else{
				this->pricePerZone[i] = pricePerZone[i];
			}

			//enum type does not need verification when inserted because it automatically verifies if they are valid and existent
			this->zones[i] = zones[i];
		}
	}
	
	void setName(string nameEvent) {
		if (lengthString(nameEvent) < MIN_CHAR || lengthString(nameEvent) > MAX_CHAR)
			throw new CustomException("Invalid name length");
		this->nameEvent = nameEvent;
	}

	void setLocation(char* location) {
		if (strlen(location) < MIN_CHAR || strlen(location) > MAX_CHAR)
			throw new CustomException("Invalid location length");
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy(this->location, location);
	}

	void setType(EventType type) {
		this->type = type;
	}

	string getNameEvent() {
		return this->nameEvent;
	}

	char* getLocation() {
		char* copy = new char[strlen(location) + 1];
		strcpy(copy, location);
		return copy;
	}

	string getType() {
		if (type == Movie)
			return "Movie";
		else if (type == Football)
			return "Football";
		else if (type == Concert)
			return "Concert";
		else if (type == Other)
			return "Other";
	}

	int* getNoSeatsPerZone() {
		int* copy = new int[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = this->noSeatsPerZone[i];
		}
		return copy;
	}

	int getNoZones() {
		return this->noZones;
	}

	string* getZones() {
		string* copy = new string[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = convertorTicketTypeToString(this->zones[i]);
		}
		return copy;
	}

	float* getPricePerZone() {
		float* copy = new float[this->noZones];
		for (int i = 0; i < this->noZones; i++) {
			copy[i] = pricePerZone[i];
		}
		return copy;
	}

	static string convertorTicketTypeToString(TicketType zone) {
		string result;
		if (zone == A)
			result = "A";
		else if (zone == B)
			result = "B";
		else if (zone == C)
			result = "C";
		else if (zone == VIP)
			result = "VIP";
		return result;
	}

	static int lengthString(string word) {
		int count = 0;
		for (int i = 0; word[i] != '\0'; i++) {
			count++;
		}
		return count;
	}
};
int Event::NO_EVENTS_CREATED = 0;
const float Event:: MIN_PRICE = 100;
const float Event:: MAX_PRICE = 1500;
const TicketType Event::array[5] = { A,B,C,VIP };

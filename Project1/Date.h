#pragma once
#include <exception>
#include <iostream>
using namespace std;

class Date {
protected:
    int day;
    int month;

public:
    Date() {
        setDay(1);
        setMonth(1);
    }
    Date(int day, int month) {
        setDay(day);
        setMonth(month);
    }
    void setDay(int day) {
        if (day < 1 || day > 32) {
            throw new CustomException("Invalid day!");
        }
        this->day = day;
    }
    void setMonth(int month) {
        if (month < 1 || month > 12) {
            throw new CustomException("Invalid month!");
        }
        this->month = month;
    }
    int getDay() { return this->day; }
    int getMonth() { return this->month; }

    virtual void setYear() {}
    
     string getDate_string() {
         return to_string(this->day) + "-" + to_string(this->month);
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

class Birthday : public Date {
protected:
    int year;
public:
    Birthday() {
        setDay(1);
        setMonth(1);
        setYear(getCurrentYear()-18);
    }
    Birthday(int day, int month, int year) {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    virtual void setYear(int year) {
        if (year > (getCurrentYear() - 18) || year < (getCurrentYear() - 100)) {
            throw new CustomException("Invalid year!");
        }
        this->year = year;
    }
    int getYear() { return this->year; }
};

class EventDate : public Date {
protected:
    int year;

public:
    EventDate() {
        setDay(1);
        setMonth(1);
        setYear(getCurrentYear());
    }
    EventDate(int day, int month, int year) {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    virtual void setYear(int year) {
        if (year < getCurrentYear()) {
            throw new CustomException("Invalid year of event!");
        }
        this->year = year;
    }
    int getYear() { return this->year; }
};

ostream& operator<<(ostream& out, Birthday date) {
    out << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
    return out;
}
ostream& operator<<(ostream& out, EventDate date) {
    out << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
    return out;
}
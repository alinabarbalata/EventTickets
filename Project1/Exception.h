#pragma once
#include <iostream>
#include <exception>
using namespace std;

class CustomException : public exception {
private:
	string message = "Error! ";
public:
	CustomException(string msg="") {
		message = message + msg;
	}
	const char *what() {
		return message.c_str();
	}
};

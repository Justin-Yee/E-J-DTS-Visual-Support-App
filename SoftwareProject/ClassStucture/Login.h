#pragma once

#include "DBConn.h"

using namespace std;
#include <iostream>
#include <string>

class Login
{
private:
	string sample;
	string database[100]; // Dummy structure
	string passwords[100]; // Dummy structure
	int classification[100]; // Dummy structure
	bool validity1;
	bool validity2;
	bool validity3;
	string currEmail;

public:

	Login();

	bool getVal1();
	bool getVal2();
	bool getVal3();

	void error(string err);
	void nameCheck(string n);
	void validityCheck(string v);
	void passCheck(int n);

	string getCurrUser();

};


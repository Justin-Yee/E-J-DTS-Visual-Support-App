#pragma once

#include <string>
#include "DBConn.h"


using namespace std;
#include <iostream>

class User
{
public:
	string name;
	string type;
	string location;

private:
	
	DBConn call;
	string email; 
	
public:

	User();
	User(string currEmail);

	string getName();
	string getType();
	string getEmail();
	string getLocation();

	void updateType();
	void updateLocation();

	User* operator=(User const& x);
};


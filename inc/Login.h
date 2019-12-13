#ifndef TT_LOGIN
#define TT_LOGIN

#include "DBConn.h"

using namespace std;
#include <iostream>
#include <string.h>

class Login
{
public:
	string sample;
	int sampleLng;
	int index;

private:
	string database[100]; // Dummy structure
	string passwords[100]; // Dummy structure
	int classification[100]; // Dummy structure
	bool validity1;
	bool validity2;
	bool validity3;
	string currEmail;
	string encoded;

public:

	Login();

	bool getVal1();
	bool getVal2();
	bool getVal3();

	void debug(string d);
	void error(string err);
	string affine_encode(string plaintext);
	void nameCheck(string n);
	void validityCheck(string v);
	void passCheck(int n);
	void domainLength(string s);

	void updatePassword(int index, string pass);

	string getCurrUser();

};

#endif

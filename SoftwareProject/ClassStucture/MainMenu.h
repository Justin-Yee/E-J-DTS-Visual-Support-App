#pragma once
#include "DBConn.h"
#include "User.h"
using namespace std;
#include <iostream>
#include <string>

class MainMenu
{
public: 
	bool running;
	bool selectHome;
	bool selectReports;
	bool selectLogout;
	bool selectContacts;
	bool passChange;
	string newPass;

private:
	string passwords[100]; // Dummy structure
	bool subReport;
	bool exReport;
	bool urgReport;
	bool abt;
	int his;
	int maxHistory;
	string history[1];
	string selectionTopBar;
	string encoded;
	bool passUpdate;
	User current;

public:

	MainMenu(User x);

	void debug(string d);
	void error(string err);
	string affine_encode(string plaintext);
	void displayMain(int index);
	void displayCreate();
	void displayList();
	void displayUrgList();
	void displayReport();
	void displayHistory();
	void displayAbout();
	void displayContact();
	void displayLogout();

};


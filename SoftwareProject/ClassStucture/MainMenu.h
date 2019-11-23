
#ifndef TT_MAINMENU
#define TT_MAINMENU

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

private:
	bool subReport;
	bool exReport;
	bool urgReport;
	bool abt;
	int his;
	int maxHistory;
	string history[1];
	string selectionTopBar;
	User current;

public:

	MainMenu(User x);

	void debug(string d);
	void error(string err);
	void displayMain();
	void displayCreate();
	void displayList();
	void displayUrgList();
	void displayReport();
	void displayHistory();
	void displayAbout();
	void displayContact();
	void displayLogout();

};

#endif
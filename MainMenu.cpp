#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/*
	MAIN MENU (After Login):
		1. Home
			a. Submit Report
			b. Existing Reports
			c. Logout
		2. Reports
		3. About
		4. Contact
*/

// Top bar checks
bool running = true;
bool selectHome = true;
bool selectReports = false;
bool selectLogout = false;
bool selectContacts = false;

int his = 0;
string history[5];

void debug(string dbg) {
	cout << "DEBUG: " << dbg << endl;
}

void error(string err) {
	cout << "ERROR: " << err << endl;
}

void home() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home (Selected)\n2. Reports\n3. Contact\n4. Logout\n\t\t\t";
	while (selectHome) {
		cin >> selectionTopBar;
		history[his] = selectionTopBar; his = (his + 1) % 5;
		// Home
		if (selectionTopBar == "1") { error("Home currently selected."); }
		// Reports
		else if (selectionTopBar == "2") {
			selectHome = false;	selectReports = true; history[his] = selectionTopBar; his = (his + 1) % 5;
			cout << history[his] << endl;
		}
		// Contacts
		else if (selectionTopBar == "3")	{ selectHome = false;	selectContacts = true; history[his] = selectionTopBar; his = (his + 1) % 5;}
		// Logout
		else if (selectionTopBar == "4")	{ selectHome = false;	selectLogout = true; }
		// Invalid Input
		else { error("Invalid Input"); }
	}	
}

void reports() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n3. Contact\n4. Logout\n\t\t\t";
	while (selectReports) {
		cin >> selectionTopBar;
		history[his] = selectionTopBar; his = (his + 1) % 5;
		// Home
		if (selectionTopBar == "1")			{ selectReports = false;	selectHome = true; history[his] = selectionTopBar; his = (his + 1) % 5;}
		// Reports
		else if (selectionTopBar == "2")	{ error("Reports currently selected."); }
		// Contacts
		else if (selectionTopBar == "3")	{ selectReports = false;	selectContacts = true; history[his] = selectionTopBar; his = (his + 1) % 5;}
		// Logout
		else if (selectionTopBar == "4")	{ selectReports = false;	selectLogout = true; }		
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

void contact() {
	string selectionTopBar;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home\n2. Reports\n3. Contact (Selected)\n4. Logout\n\t\t\t";
	while (selectContacts) {
		cin >> selectionTopBar;
		// Home
		if (selectionTopBar == "1")			{ selectContacts = false;	selectHome = true; history[his] = selectionTopBar; his = (his + 1) % 5;}
		// Reports
		else if (selectionTopBar == "2")	{ selectContacts = false; selectReports = true; history[his] = selectionTopBar; his = (his + 1) % 5;}
		// Contacts
		else if (selectionTopBar == "3")	{ error("Contacts currently selected."); }
		// Logout
		else if (selectionTopBar == "4")	{ selectContacts = false;	selectLogout = true; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

void logout() {
	string logout;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nAre you sure you would like to Log Out? (Y/N)\n\t\t\t";
	while (selectLogout) {
		cin >> logout;
		if (logout == "Y" || logout == "y") {
			selectLogout = false;
			running = false;
		}
		else if (logout == "N" || logout == "n") {
			debug("Not logging out");
			if (his = 0) {
				his = 5;
			}
			else {
				his = his - 1;
			}
			cout << "History: " << history[his] << endl;
			if (history[his] == "1") { selectLogout = false; selectHome = true; debug("Going to Home"); }
			else if (history[his] == "2")	{ selectLogout = false; selectContacts = true; debug("Going to Reports");}
			else if (history[his] == "3")	{ selectLogout = false; selectContacts = true; debug("Going to Contacts");}
			else { error("No history found."); }
		}
		// Invalid Input
		else { error("Invalid Input"); }
	}
}

int main(void) {
	while (running) {
		if (selectHome) {
			home();
		}
		if (selectReports) {
			reports();
		}
		if (selectContacts) {
			contact();
		}
		if (selectLogout) {
			logout();
		}
	}
	return 0;
}
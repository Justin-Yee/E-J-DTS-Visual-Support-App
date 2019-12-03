// Software Engineering CSE 120 UC MERCED FALL 2019
// Group Members : Bailey Kandler , Mark McCullough , Krishan Patel , Justin Yee
// E & J Gallo Defect Tracking Support App : Proof of Concept Implementation
// Last Updated : 08:53, 19 November 2019 

// Object Oriented Approach to extract Database information into instances of a class in the application
// As well as running an instance of the login functionality etc.

using namespace std;
#include <iostream>
#include <string>
#include <ctime>

#include "CreateReport.h"
#include "Credentials.h"
#include "DBConn.h"
#include "Login.h"
#include "MainMenu.h"
#include "ReportHistory.h"
#include "ReportList.h"
#include "User.h"
#include "ViewReport.h"

int main() { 

	// Current User Index
	Credentials C;

	// Login Logic
	Login L;
	string userName;

	cout << "Username:\t";
	cin >> userName;

	L.domainLength(L.sample);

	int errCtr = 0;																// Allows a certain amount of invalid usernames before terminating
	bool nameVerify = true;														// Small loop to input username as valid
	while (!L.getVal1() && errCtr <= 5) {
		cout << "Username:\t";
		cin >> userName;

		if (userName.size() > L.sampleLng && !userName.empty()) {
			L.validityCheck(userName);
			if (L.getVal1()) L.nameCheck(userName);
		}
		if (!L.getVal1()) {
			errCtr++;
			if (errCtr >= 5) {
				L.error("Invalid username.");
			}
		}
	}

	if (L.getVal1() && L.getVal2() && L.getVal3()) {
		cout << "Success!" << endl;
	}

	C.setIndex(L.index);

	// Main Menu Logic

	/*
	MAIN MENU (After Login):
		1. Home
			a. Upcoming Reports (What's due within the next n-days)
			b. Change Password
			c. About
		2. Reports
			a. Submit Report
			b. Existing Reports
			c. Historical Data
		3. Contact
		4. Logout
	*/
	
	MainMenu M(User(L.getCurrUser()));
	while (M.running) {
		if (M.selectHome) {
			M.displayMain(C.getIndex());
		}
		else if (M.selectReports) {
			M.displayReport();
		}
		else if (M.selectContacts) {
			M.displayContact();
		}
		else if (M.selectLogout) {
			M.displayLogout();
		}
	}

	L.updatePassword(C.getIndex(), M.newPass);

	return 0; 
}
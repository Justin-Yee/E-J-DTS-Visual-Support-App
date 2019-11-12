// Software Engineering CSE 120 UC MERCED FALL 2019
// Group Members : Bailey Kandler , Mark McCullough , Krishan Patel , Justin Yee
// E & J Gallo Defect Tracking Support App : Proof of Concept Implementation
// Last Updated : 09:27, 12 November 2019 

// Object Oriented Approach to extract Database information into instances of a class in the application
// As well as running an instance of the login functionality etc.


#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;
#include <iostream>
#include <string>
#include <ctime>

#include "CreateReport.h"
#include "Login.h"
#include "MainMenu.h"
#include "ReportHistory.h"
#include "ReportList.h"
#include "User.h"
#include "ViewReport.h"

int main() { 

	// Login Logic
	Login L;
	string userName;

	cout << "Username:\t";
	cin >> userName;

	if (userName.size() > 12 && !userName.empty()) {
		L.validityCheck(userName);
	}
	else {
		L.error("Too short of username.");
	}
	if (L.getVal1()) { L.nameCheck(userName); }


	if (L.getVal1() && L.getVal2() && L.getVal3()) {
		cout << "Success!" << endl;
	}

	// Main Menu Logic


	return 0; 
}
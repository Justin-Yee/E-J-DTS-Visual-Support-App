// Software Engineering CSE 120 UC MERCED FALL 2019
// Group Members : Bailey Kandler , Mark McCullough , Krishan Patel , Justin Yee
// E & J Gallo Defect Tracking Support App : Proof of Concept Implementation
// Last Updated : 00:52, 6 December 2019 
#pragma warning(disable : 4996)
#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
#include <Wt/Dbo/backend/Sqlite3.h> // For specific SQLite3 connection
#include <Wt/Dbo/ptr.h>
namespace dbo = Wt::Dbo; // For controlling API functionality
#include <tuple>
#include <random>

using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

// Variables to Store Database Information

// Report Data to be sent into DB
struct NewReport{
	int dtsID;
	int workOrderNumber;
	string materialGroup;
	string defectName;
	int machineLine;
	tm incidentDate;
	string incidentClassification;
	string defectClassification;
	string defectSeverity;
	string supplierName;
	int itemNumber;
	string causeComment;
	string actionComment;
	string reportStatus;

	void inputReportInfo() {
		// Use input file or input stream to take in information from user
		// Set class variables to the input
		cout << "Creating Report" << endl; cout << "********************" << endl;

		cout << "Enter the Work Order Number :\t\t";		cin >> workOrderNumber;
		cout << "Enter the Material Group :\t\t";			cin >> materialGroup; 
		cout << "Enter the Name of the Defect :\t\t";		cin >> defectName; 
		cout << "Enter the Machine Line :\t\t";				cin >> machineLine; 
		cout << "Enter the Day :\t\t\t\t";					cin >> incidentDate.tm_mday; 
		cout << "Enter the Month :\t\t\t";					cin >> incidentDate.tm_mon; 
		cout << "Enter the Year :\t\t\t";					cin >> incidentDate.tm_year; 
		cout << "Enter the Incident Classification :\t";	cin >> incidentClassification; 
		cout << "Enter the Defect Classification :\t";		cin >> defectClassification; 
		cout << "Enter the Defect Severity :\t\t";			cin >> defectSeverity; 
		cout << "Enter the Supplier Name :\t\t";			cin >> supplierName; 
		cout << "Enter the Item Number :\t\t\t";			cin >> itemNumber; 
		cout << "Enter a Comment on the Cause :\t\t";		cin >> causeComment; 
		cout << "Enter a Recommended Action :\t\t";			cin >> actionComment; 

		cout << "********************" << endl; cout << "Report Created" << endl;
	}
};

// Report Data to be extracted from DB
struct Report {
	int dtsID;
	int workOrderNumber;
	string materialGroup;
	string defectName;
	int machineLine;
	tm incidentDate;
	string incidentClassification;
	string defectClassification;
	string defectSeverity;
	string supplierName;
	int itemNumber;
	string causeComment;
	string actionComment;
	string reportStatus;
	
	void printBriefReport() {
		// Output of Full Report Information
		cout << "********************" << endl;

		cout << "DTS ID :\t\t\t" << dtsID << "\nWork Order Number : \t\t" << workOrderNumber << endl;
		cout << "Material Group :\t\t" << materialGroup << "\nDefect Name :\t\t\t" << defectName << endl;
		cout << "Current Status :\t\t" << reportStatus << endl;

		cout << "********************" << endl;
	}
	void printFullReport() {
		// Output of Full Report Information
		cout << "********************" << endl;

		cout << "DTS ID :\t\t\t" << dtsID << "\nWork Order Number : \t\t" << workOrderNumber << endl;
		cout << "Material Group :\t\t" << materialGroup << "\nDefect Name \t\t\t" << defectName << endl;
		cout << "Current Status :\t\t" << reportStatus << endl;
		cout << "Machine Line :\t\t\t" << machineLine << endl;
		cout << "Incident Date :\t\t\t" << incidentDate.tm_mon << " " << incidentDate.tm_mday << ", " << incidentDate.tm_year << endl;
		cout << "Incident Classification :\t" << incidentClassification << "\nDefect Classification :\t\t" << defectClassification << endl;
		cout << "Defect Severity :\t\t" << defectSeverity << endl;
		cout << "Supplier :\t\t\t" << supplierName << "\nItem Number :\t\t\t" << itemNumber << endl;
		cout << "Suggested Cause :\t\t" << causeComment << endl;
		cout << "Suggested Action :\t\t" << actionComment << endl;

		cout << "********************" << endl;
	}

	template <class Action>
	void persist(Action& a) { }
};

// User Data
struct User {
	string name;
	string type;
	string location;
	string email;

	template <class Action>
	void persist(Action& a) { }
};

// Report Lists (Full, Urgent, History)
vector<Report*> fullList; vector<Report*> urgList; vector<Report*> histList; int currItem = 1;

// Current Index of User
User current; int index = 0;

// Current DTS ID (increments every time a Report is Created)
int dts_id_index = 1;

// Main Menu
bool running = true;
bool selectHome = true; bool selectReports = false; bool selectLogout = false; bool selectContacts = false;
bool subReport = false; bool exReport = false; bool hisReport = false; bool indivReport = false; bool urgReport = false; bool abt = false;
int his = 0; int maxHistory = 10; string history[10];
string selectionTopBar;
bool passUpdate = false; bool passChange = false; string newPass;

// Login 
string sample = "username@ejgallo.com"; int sampleLng = 0;
string database[100] = { "kpatel@ejgallo.com", "bkandler@ejgallo.com", "markmcc2950@ejgallo.com", "jyee@ejgallo.com", "test@ejgallo.com" };
string passwords[100] = { "K;``#DYP", "K;``#DYPO", "K;``#DYPV", "K;``#DYP]" };
string encoded;
int classification[100] = { 2, 0, 1, 1, 0 };
bool validity1 = false; bool validity2 = false; bool validity3 = false;
string currEmail;

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

// Functions to Run Individual Logics

// Debugging Fucntions
void debug(string d) {
	cout << "DEBUG: " << d << endl;
}
void error(string err) {
	cout << "ERROR: " << err << endl;
}

// Database Functions
dbo::Session* session = new dbo::Session;

User retrieveUser(string email) {
	// Use input email to extract name, type, and location from database

	tuple<string, string, string> result = session->query < tuple<string, string, string> >
		("select user_name, user_type, user_location from User_Relation R").where("R.user_email = " + email);

	// Set the variables of User* x with the DB call above
	User x;

	x.name = get<0>(result);
	x.type = get<1>(result);
	x.location = get<2>(result);

	return x;
}
void insertReportInfo(NewReport* n) {
	// Use input variable to push a new Report Snapshot and Report Details tuple

	dbo::Transaction transaction(*session);
	unique_ptr<Report> input{ new Report };
	dts_id_index++;
	input->dtsID = dts_id_index;
	input->workOrderNumber = n->workOrderNumber;
	input->materialGroup = n->materialGroup;
	input->defectName = n->defectName;
	input->machineLine = n->machineLine;
	input->incidentDate = n->incidentDate;
	input->incidentClassification = n->incidentClassification;
	input->defectClassification = n->defectClassification;
	input->defectSeverity = n->defectSeverity;
	input->supplierName = n->supplierName;
	input->itemNumber = n->itemNumber;
	input->causeComment = n->causeComment;
	input->actionComment = n->actionComment;
	input->reportStatus = "open";

	dbo::ptr<Report> inputPtr = session->add(move(input));

	// member variables of  ins  input item are pushed to corresponding database attributes
}
Report* retrieveReportInfo(int id) {
	// Use input DTS ID to extract the rest of the info about the DTS from the database

	tuple<int, string, string, int, int, int, int, string, string, string, string, int, string, string, string> result = 
		session->query < tuple<int, string, string, int, int, int, int, string, string, string, string, int, string, string, string> >
		("S.workorder_number, S.material_group, S.defect_name, machine_line, DAY(incident_date), MONTH(incident_date), YEAR(incident_date), incident_classification, defect_classification, defect_severity, supplier_name, item_number, cause_comment, action_comment, report_status from Incident_details D, Incident_snapshot S")
		.where("D.dts_id = S.dts_id and D.dts_id = " + id);
	// Set the variables of ViewReport* x with the DB call above
	Report* x = new Report;

	x->workOrderNumber = get<0>(result);
	x->materialGroup = get<1>(result);
	x->defectName = get<2>(result);
	x->machineLine = get<3>(result);
	x->incidentDate.tm_mday = get<4>(result);
	x->incidentDate.tm_mon = get<5>(result);
	x->incidentDate.tm_year = get<6>(result);
	x->incidentClassification = get<7>(result);
	x->defectClassification = get<8>(result);
	x->defectSeverity = get<9>(result);
	x->supplierName = get<10>(result);
	x->itemNumber = get<11>(result);
	x->causeComment = get<12>(result);
	x->actionComment = get<13>(result);
	x->reportStatus = get<14>(result);

	return x;
}
vector<Report*> generateReportList(User* curr) {
	// Based on current User (Type and Location) extract a list of DTS IDs appropriate to User
	vector<int> ids;
	// Use that list of IDs to generate a list of Reports
	// ReportList* x->list is a list of ViewReports
	vector<Report*> x; 
	// i.e.
	ids.resize(5); // Count of valid reports
	x.resize(5); // Count of valid reports
	x[0] = retrieveReportInfo(ids[0]);

	/* Call Database Here */

	return x;
}
vector<Report*> generateUrgentReports(User* curr) {
	// Based on current User (Type and Location) extract a list of DTS IDs appropriate to User
	// Also find the Reports that are within the past week of current session

	time_t t = time(0); // Get Timestamp
	tm* now = localtime(&t); // Holds current time :: now->tm_mday / now->tm_mon / now->tm_year	

	vector<int> ids;
	// Use that list of IDs to generate a list of Reports
	// ReportList* x->list is a list of ViewReports
	vector<Report*> x;
	// i.e.
	ids.resize(5); // Count of valid reports
	x.resize(5); // Count of valid reports
	x[0] = retrieveReportInfo(ids[0]);

	/* Call Database Here */

	return x;
}
vector<Report*> generateReportHistory(int itemNum, User* curr) {
	// Based on current User (Type and Location) and the Item Number in question
	//	extract a history of Reports that involved that Item Number that the User would need to see

	// Extract the DTS IDs that involve the input Item Number
	vector<int> ids;
	// ReportHistory* x->list is a list of ViewReports
	vector<Report*> x;
	// i.e.
	ids.resize(5); // Count of valid reports
	x.resize(5); // Count of valid reports
	x[0] = retrieveReportInfo(ids[0]);

	/* Call Database Here */

	return x;
}
int retrieveCurrID() {
	// Get the most current ID

	int result = session->query< int >("select MAX(dts_id) from Incident_Snapshot");

	return result;
}

// Encoding Function for Password Safety
string affine_encode(string plaintext) {
	int a = 7;
	int b = 23;
	int m = 89;
	// Convert string to const char and find the size
	string text = plaintext.data();
	int size = text.length();
	encoded.resize(size);

	vector<int> intText; intText.resize(size);
	vector<int> encText; encText.resize(size);

	for (int i = 0; i < size; i++) {
		if (text[i] != ' ') {
			encText[i] = ((((int(text[i]) - 33) * a + b) % m) + 33);
		}
		else {
			encText[i] = text[i];
		}
	}
	string encrypted; encrypted.resize(size);

	for (int i = 0; i < size; i++) {
		encrypted[i] = char(encText[i]);
		encoded[i] = encrypted[i];
	}

	return encrypted;
}

// Login Functions
void domainLength(string s) {
	int counter = 0;
	bool count = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '@') {
			count = true;
		}
		if (count) {
			counter++;
		}
	}
	sampleLng = counter;
}
void updatePassword(int index, string pass) {
	passwords[index] = pass;
}
void passCheck(int n) {
	int index = n;
	string password;
	int i = 0;
	cout << "Password:\t";
	cin >> password;
	if (password.size() == passwords[index].size()) {
		password = affine_encode(password);										// Encode the password inputted to our global string variable
		password = encoded;														// Save the encoded password to our original variable here
		//debug(password);
		while (!validity3) {
			// If no password saved, return error. (Shouldn't be able to get here without a password though)
			if (passwords[index].empty()) {
				error("Empty Password Slot. Invalid Username slot.");
				break;
			}
			int size = passwords[index].size();
			if (password[i] == passwords[index][i]) {
				i++;
				if (i == size) {
					validity3 = true;
					break;
				}
				else {
					error("Invalid Password.");
					break;
				}
			}
		}
	}
	else {
		error("Ivalid Password.");
	}
}
void validityCheck(string v) {
	int size = v.size();

	// Check if user name is valid
	if (size > sampleLng) {
		// Check that we have @ejgallo.com at the end (referenced against our sample)
		for (int i = 0; i < sampleLng; i++) {
			if (v[size - sampleLng + i] != sample[sample.size() - sampleLng + i]) {
				error("Invalid Username.");
				validity1 = false;
				break;
			}
			else {
				validity1 = true;
			}
		}
	}
	else {
		error("Invalid Username.");
		validity1 = false;
	}
}
void nameCheck(string n) {
	int dbSize = (sizeof(database)) / 32;
	int i = 0;
	int j = 0;
	while (!validity2) {
		int size = database[j].size();
		if (database[j].size() == n.size() && database[j][i] == n[i]) {	// Check first if the two string sizes match before progressing
			if (n[i] == database[j][i]) {
				i = (i + 1);
				if (n[i] == '@') {
					if (!passwords[j].empty()) {
						validity2 = true;
						currEmail = database[j];
						index = j;
						passCheck(j);
					}
					else {
						error("No matching password in system for username entered.");
					}
				}
			}
		}
		else {
			j++;
			i = 0;
			validity2 = false;
		}
		if (database[j].empty()) {
			error("Empty slot. Username Not Found");
			break;
		}
		if (j >= dbSize) { error("Username Not Found."); break; }
	}
}

// Main Menu Functions
void displayHistory(int itemNum, User* c) {
	//histList = generateReportHistory(itemNum, c);
	// Iterate over the List and print out the Information we need 
	for (int i = 0; i < histList.size(); i++) {
		if (histList[i]->itemNumber == itemNum) {
			cout << "********************" << endl;
			cout << "Item Number :\t\t" << itemNum << endl;
			cout << "Supplier :\t" << histList[i]->supplierName << "\nMachine Line :\t" << histList[i]->machineLine << endl;
			cout << "********************" << endl;
		}
	}	
}
void displayList(User* c) {
	//fullList = generateReportList(c);
	// Iterate over list to print Snapshot of each DTS
	for (int i = 0; i < fullList.size(); i++) {
		fullList[i]->printBriefReport();
	}
}
void displayUrgList(User* c) {
	//urgList = generateUrgentReports(c);
	// Iterate over list to print the Most Urgent Reports for User to view
	for (int i = 0; i < urgList.size(); i++) {
		urgList[i]->printBriefReport();
	}
}
void displayCreate() {
	NewReport* r = new NewReport;
	r->inputReportInfo();
	//insertReportInfo(r);
}
void displayAbout() {
	cout << "Generic Information..." << endl;
	cout << "[Placeholder Text]" << endl;
}
void displayLogout() {
	string logout;														// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nAre you sure you would like to Log Out? (Y/N)\n";
	while (selectLogout) {
		cout << "\t\t\t";
		cin >> logout;
		if (logout == "Y" || logout == "y") {
			debug("Successfully Logged Out!");
			selectLogout = false;
			running = false;
		}
		else if (logout == "N" || logout == "n") {
			debug("Not logging out");
			if (his == 0) {
				his = maxHistory - 1;
			}
			else {
				his--;
			}
			if (history[his] == "1") { selectLogout = false; selectHome = true; debug("Going to Home"); }
			else if (history[his] == "2") { selectLogout = false; selectReports = true; debug("Going to Reports"); }
			else if (history[his] == "3") { selectLogout = false; selectContacts = true; debug("Going to Contacts"); }
			else { error("No history found."); }
		}
		// Invalid Input
		else { error("Invalid Input"); }
	}
}
void displayContact() {
	cout << "\nTOP BAR:\n1. Home\n2. Reports\n3. Contact (Selected)\n4. Logout\n";
	while (selectContacts) {
		cout << current.email << endl;
		cout << current.name << endl;
		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { selectContacts = false;	selectHome = true;		history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Reports
		else if (selectionTopBar == "2") { selectContacts = false;	selectReports = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Contacts
		else if (selectionTopBar == "3") { error("Contacts currently selected."); }
		// Logout
		else if (selectionTopBar == "4") { selectContacts = false;	selectLogout = true; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}
void displayReport() {
	cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n\tc. Historical Data\n\td. Individual Report\n3. Contact\n4. Logout\n";
	while (selectReports) {

		// SUBMIT REPORTS
		if (subReport) {
			debug("Fill in New Reports Here...");
			/*
				We'll declare our report-specific variables here.
				When we reach the end, we'll have a confirmation option to confirm the report has been filled out as desired.
				Once confirmed, subReport = false and we print out the selectHome selection menu again.
			*/

			displayCreate(); // Function to take Input and send it to a Report Object and the Database

			subReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n\tc. Historical Data\n\td. Individual Report\n3. Contact\n4. Logout\n";
		}
		// EXISTING REPORTS
		else if (exReport) {
			debug("History of Reports Show Here...");
			/*
				This is where our history of reports will show up.
				We will have a list of size n shown at any time. Initially will be reports 0 through n.
					If we hit a 'next' button, it will move to reports n+1 through n+n.
					We can keep hitting next until we reach the end.
						|| if (n+n > total list size) {
						|| 	 Gray out 'next' button
						|| }
					We can maybe keep track of the amount of "next" buttons hit, with each button push, nextButtonPushes++, then...
						|| if (n * nextButtonPushes > total list size) {
						|| 	 Gray out 'next' button
						|| }
					We can also have a previous button that lights up once we hit next the first time
						With each push, nextButtonPushes--;
						|| if (nextButtonPushes == 0) {
						||	 Gray out 'previous' button
						|| }
				Once we're done, at any point we can push an 'exit' button to go back to the selectHome selection menu again
			*/

			displayList(&current); // Function to display the list of Reports

			exReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n\tc. Historical Data\n\td. Individual Report\n3. Contact\n4. Logout\n";
		}else if (hisReport) {
			int d;
			cout << "Enter Item Number your would like to View History for :\t";
			cin >> d;
			debug("Report History of Item Number : " + d);
			
			displayHistory(d, &current);

			subReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n\tc. Historical Data\n\td. Individual Report\n3. Contact\n4. Logout\n";
		}else if (indivReport) {
			int d;
			cout << "There are : " << fullList.size() << " Reports you can View." << endl;
			cout << "Enter the number of the Report you would like to view :\t";
			cin >> d;

			fullList[d]->printFullReport();

			subReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home\n2. Reports (Selected)\n\ta. Submit Report\n\tb. Existing Reports\n\tc. Historical Data\n\td. Individual Report\n3. Contact\n4. Logout\n";
		}

		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { selectReports = false;	selectHome = true;			history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Reports
		else if (selectionTopBar == "2") { error("Reports currently selected."); }
		// Contacts
		else if (selectionTopBar == "3") { selectReports = false;	selectContacts = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Logout
		else if (selectionTopBar == "4") { selectReports = false;	selectLogout = true; }
		// REPORTS SCREEN (Submit Reports, Existing Reports)
		else if (selectionTopBar == "a") { subReport = true;								history[his] = selectionTopBar;	his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "b") { exReport = true;									history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "c") { hisReport = true;									history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "d") { indivReport = true;									history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Invalid Input
		else { error("Invalid Input"); }
	}
}
void displayMain(int index) {
	// Top Bar selections (Home, Reports, About, Contact)
	cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
	while (selectHome) {
		// UPCOMING REPORTS
		if (urgReport) {
			debug("List of Top 3 Upcoming Reports Here...");
			/*
				We'll declare our report-specific variables here.
				When we reach the end, we'll have a confirmation option to confirm the report has been filled out as desired.
				Once confirmed, subReport = false and we print out the selectHome selection menu again.
			*/

			displayUrgList(&current);

			urgReport = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
		}
		// CHANGE PASSWORD
		else if (passChange) {
			string change;
			debug("Change your password...");
			cout << "Would you like to change your password? (Y/N)" << endl;
			cin >> change;
			if (change == "Y" || change == "y") {
				string password;
				string password2;
				string password3;
				debug("Changing password!");
				cout << "Please enter current password:\t";
				cin >> password;
				password = affine_encode(password);
				password = encoded;
				bool passMatch = false;
				if (passwords[index] == password) {
					debug("Password match!");
					passMatch = true;
					if (passMatch) {
						cout << "Please enter your new password:\t";
						cin >> password2;
						cout << "Please re-enter your new password:\t";
						cin >> password3;
						if (password2 == password3) {
							password2 = affine_encode(password2);
							password2 = encoded;
							passwords[index] = password2;
							passUpdate = true;
						}
					}
				}
			}
			else if (change == "N" || change == "n") {
				debug("Not changing password...");
				passChange = false;
				cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
			}
		}
		// ABOUT INFORMATION
		else if (abt) {
			debug("About information...");
			displayAbout();
			abt = false;
			history[his] = "1"; his = (his + 1) % maxHistory;
			cout << "\nTOP BAR:\n1. Home (Selected)\n\ta. Upcoming Reports\n\tb. Change Password\n\tc. About\n2. Reports\n3. Contact\n4. Logout\n";
		}

		// User input of where to navigate to
		cout << "\t\t\t";
		cin >> selectionTopBar;
		// TOP BAR SELECTION (Home, Reports, Contacts, Logout)
		// Home
		if (selectionTopBar == "1") { error("Home currently selected."); }
		// Reports
		else if (selectionTopBar == "2") { selectHome = false;	selectReports = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Contacts
		else if (selectionTopBar == "3") { selectHome = false;	selectContacts = true;	history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Logout
		else if (selectionTopBar == "4") { selectHome = false;	selectLogout = true; }

		// HOME SCREEN SELECTION (Submit Report, Existing Reports, About)
		else if (selectionTopBar == "a") { urgReport = true;							history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "b") { passChange = true;							history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		else if (selectionTopBar == "c") { abt = true;									history[his] = selectionTopBar; his = (his + 1) % maxHistory; }
		// Invalid Input
		else { error("Invalid Input"); }
	}

	if (passUpdate) {
		newPass = passwords[index];
	}
}

// Generate In-Program Data (Sample Display Data)
void fillData() {
	for (int i = 0; i < fullList.size(); i++) {
		default_random_engine e;
		uniform_int_distribution<int> d(1000, 5000);
		uniform_int_distribution<int> f(100, 500);
		uniform_int_distribution<int> g(10, 50);
		fullList[i] = new Report; histList[i] = new Report; urgList[i] = new Report;
		fullList[i]->dtsID = i; histList[i]->dtsID = i; urgList[i]->dtsID = i;
		fullList[i]->workOrderNumber = histList[i]->workOrderNumber = urgList[i]->workOrderNumber = i * g(e);
		if (i%2 == 0) {
			fullList[i]->materialGroup = "label"; histList[i]->materialGroup = "label"; urgList[i]->materialGroup = "label";
			fullList[i]->defectName = "printing"; histList[i]->defectName = "printing"; urgList[i]->defectName = "printing";
			fullList[i]->causeComment = "faded"; histList[i]->causeComment = "faded"; urgList[i]->causeComment = "faded";
			fullList[i]->actionComment = "report"; histList[i]->actionComment = "report"; histList[i]->actionComment = "report";
			fullList[i]->incidentClassification = "hold"; histList[i]->incidentClassification = "hold"; urgList[i]->incidentClassification = "hold";
			fullList[i]->defectClassification = "minor"; histList[i]->defectClassification = "minor"; urgList[i]->defectClassification = "minor";
			fullList[i]->supplierName = "multicolor"; histList[i]->supplierName = "multicolor"; urgList[i]->supplierName = "multicolor";
		}
		else {
			fullList[i]->materialGroup = "glass"; histList[i]->materialGroup = "glass"; urgList[i]->materialGroup = "glass";
			fullList[i]->defectName = "splice"; histList[i]->defectName = "splice"; urgList[i]->defectName = "splice";
			fullList[i]->causeComment = "defective"; histList[i]->causeComment = "defective"; urgList[i]->causeComment = "defective";
			fullList[i]->actionComment = "return"; histList[i]->actionComment = "return"; urgList[i]->actionComment = "return";
			fullList[i]->incidentClassification = "hold"; histList[i]->incidentClassification = "hold"; urgList[i]->incidentClassification = "hold";
			fullList[i]->defectClassification = "minor"; histList[i]->defectClassification = "minor"; histList[i]->defectClassification = "minor";
			fullList[i]->supplierName = "EJGallo"; histList[i]->supplierName = "EJGallo"; urgList[i]->supplierName = "EJGallo";
		}
		fullList[i]->defectSeverity = "operational"; histList[i]->defectSeverity = "operational"; urgList[i]->defectSeverity = "operational";
		fullList[i]->incidentDate.tm_mday = 6; histList[i]->incidentDate.tm_mday = 6; urgList[i]->incidentDate.tm_mday = 6;
		fullList[i]->incidentDate.tm_mon = 12; histList[i]->incidentDate.tm_mon = 12; urgList[i]->incidentDate.tm_mon = 12;
		fullList[i]->incidentDate.tm_year = 2019; histList[i]->incidentDate.tm_year = 2019; urgList[i]->incidentDate.tm_year = 2019;
		fullList[i]->itemNumber = histList[i]->itemNumber = urgList[i]->itemNumber = i + 7 * i;
		fullList[i]->machineLine = histList[i]->machineLine = urgList[i]->machineLine = i * f(e);
		fullList[i]->reportStatus = histList[i]->reportStatus = urgList[i]->reportStatus = "open";
	}
}

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

// Control the Program
int main() {
	
	cout << "Connecting to Database ... " << endl;
	// Connect to the Database	
	unique_ptr<dbo::backend::Sqlite3> sqlite3{ new dbo::backend::Sqlite3("E-G_DTS_DB_Test.db") };
	session->setConnection(move(sqlite3));	
	cout << "Connected to Database." << endl;
	cout << "Mapping DB Relations to Session ... " << endl;
	session->mapClass<User>("User_Relation"); cout << "User_Relation mapped." << endl;
	session->mapClass<Report>("Report"); cout << "Report mapped." << endl;

	// Login Logic
	domainLength(sample);

	string userName;
	int errCtr = 0;																// Allows a certain amount of invalid usernames before terminating
	bool nameVerify = true;														// Small loop to input username as valid
	while (!validity1 && errCtr <= 5) {
		cout << "Username:\t";
		cin >> userName;

		if (userName.size() > sampleLng && !userName.empty()) {
			validityCheck(userName);
			if (validity1) nameCheck(userName);
		}
		if (!validity1) {
			errCtr++;
			if (errCtr >= 5) {
				error("Invalid username.");
			}
		}
	}
	if (validity1 && validity2 && validity3) {
		cout << "Success!" << endl;
	}

	current.email = userName;
	fullList.resize(20); histList.resize(20); urgList.resize(20); fillData(); // Temporary Resizing & Data Fill (while Database calls are bugged)	
	//current = retrieveUser(userName); // Use input to get Current User Info from Database
	//dts_id_index = retrieveCurrID(); // Get the current DTS ID so that any new Reports can generate a unique ID

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
			d. Individual Report
		3. Contact
		4. Logout
	*/

	while (running) {
		if (selectHome) {
			displayMain(index);
		}
		else if (selectReports) {
			displayReport();
		}
		else if (selectContacts) {
			displayContact();
		}
		else if (selectLogout) {
			displayLogout();
		}
	}
	updatePassword(index, newPass);

	return 1;
}
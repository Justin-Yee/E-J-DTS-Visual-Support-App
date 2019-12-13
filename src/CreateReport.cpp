#include "CreateReport.h"

CreateReport::CreateReport() {
	// Set Default Values so as to not have Null entries in our Database

	dtsID = 1; // Generate from main.cpp no input required
	reportStatus = "Open"; // status = Open once report is created

	// Temporary values
	workOrderNumber = 123456789;
	materialGroup = "Empty";
	defectName = "Empty";
	machineLine = 1;
	incidentDate.tm_mday = 1; // Day of Month
	incidentDate.tm_mon = 1; // Month of Year
	incidentDate.tm_year = 2020; // Year
	incidentClassification = "Empty";
	defectClassification = "Empty";
	defectSeverity = "Empty";
	supplierName = "Empty";
	itemNumber = 12345;
	causeComment = "Empty";
	actionComment = "Empty";

	inputReportInfo();
}

void CreateReport::setID(int id) {
	dtsID = id;
}

void CreateReport::setWON(int won) {
	workOrderNumber = won;
}

void CreateReport::setMatGroup(string mat) {
	materialGroup = mat;
}

void CreateReport::setDefName(string defName) {
	defectName = defName;
}

void CreateReport::setMachLine(int machLine) {
	machineLine = machLine;
}

void CreateReport::setDate(int day, int month, int year) {
	incidentDate.tm_mday = day;
	incidentDate.tm_mon = month; 
	incidentDate.tm_year = year; 
}

void CreateReport::setIncClass(string incClass) {
	incidentClassification = incClass;
}

void CreateReport::setDefClass(string defClass) {
	defectClassification = defClass;
}

void CreateReport::setDefSev(string defSev) {
	defectSeverity = defSev;
}

void CreateReport::setSupplier(string supp) {
	supplierName = supp;
}

void CreateReport::setItemNum(int num) {
	itemNumber = num;
}

void CreateReport::setCauseComm(string cause) {
	causeComment = cause;
}

void CreateReport::setActComm(string action) {
	actionComment = action;
}

void CreateReport::setStatus(string st) {
	reportStatus = st;
}

void CreateReport::inputReportInfo() {
	// Use input file or input stream to take in information from user
	// Set class variables to the input
	cout << "Creating Report" << endl; cout << "********************" << endl;

	cout << "Enter the Work Order Number :\t\t" << endl;
	cin >> workOrderNumber; cout << endl;

	cout << "Enter the Material Group :\t\t" << endl;
	cin >> materialGroup; cout << endl;

	cout << "Enter the Name of the Defect :\t\t" << endl;
	cin >> defectName; cout << endl;

	cout << "Enter the Machine Line :\t\t" << endl;
	cin >> machineLine; cout << endl;

	cout << "Enter the Day :\t\t" << endl;
	cin >> incidentDate.tm_mday; cout << endl;

	cout << "Enter the Month :\t\t" << endl;
	cin >> incidentDate.tm_mon; cout << endl;

	cout << "Enter the Year :\t\t" << endl;
	cin >> incidentDate.tm_year; cout << endl;

	cout << "Enter the Incident Classification :\t\t" << endl;
	cin >> incidentClassification; cout << endl;

	cout << "Enter the Defect Classification :\t\t" << endl;
	cin >> defectClassification; cout << endl;

	cout << "Enter the Defect Severity :\t\t" << endl;
	cin >> defectSeverity; cout << endl;

	cout << "Enter the Supplier Name :\t\t" << endl;
	cin >> supplierName; cout << endl;

	cout << "Enter the Item Number :\t\t" << endl;
	cin >> itemNumber; cout << endl;

	cout << "Enter a Comment on the Cause :\t\t" << endl;
	cin >> causeComment; cout << endl;

	cout << "Enter a Recommended Action :\t\t" << endl;
	cin >> actionComment; cout << endl;

	cout << "********************" << endl; cout << "Report Created" << endl;
}

void CreateReport::pushToDB() {
	// Use API to apply the insert function to add to the Database
	call.insertReportInfo(this);
}
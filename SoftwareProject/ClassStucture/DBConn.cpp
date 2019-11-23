#include "DBConn.h"

DBConn::DBConn() {
	connect();
}

void DBConn::connect() {
	unique_ptr<dbo::backend::Sqlite3> sqlite3{new dbo::backend::Sqlite3("database.db")}; // replace "database.db" with actual database file
	session.setConnection(move(sqlite3));
}

User* DBConn::retrieveUser(string email) {
	// Use input email to extract name, type, and location from database

	/* Call Database Here */

	// Set the variables of User* x with the DB call above
	User* x = new User;
	
	x->name = " ";
	x->type = " ";
	x->location = " ";
	
	return x;
}

void DBConn::insertReportInfo(CreateReport* ins) {
	// Use input variable to push a new Report Snapshot and Report Details tuple

	/* Call Database Here */

	// member variables of  ins  input item are pushed to corresponding database attributes
}

ViewReport* DBConn::retrieveReportInfo(int id) {
	// Use input DTS ID to extract the rest of the info about the DTS from the database

	/* Call Database Here */

	// Set the variables of ViewReport* x with the DB call above
	ViewReport* x;

	x->workOrderNumber = 1;
	x->materialGroup = " ";
	x->defectName = " ";
	x->machineLine = 1;
	x->incidentDate.tm_mday = 1; 
	x->incidentDate.tm_mon = 1; 
	x->incidentDate.tm_year = 1; 
	x->incidentClassification = " ";
	x->defectClassification = " ";
	x->defectSeverity = " ";
	x->supplierName = " ";
	x->itemNumber = 1;
	x->causeComment = " ";
	x->actionComment = " ";
	x->reportStatus = " ";

	return x;
}

ReportList* DBConn::generateReportList(User* curr) {
	// Based on current User (Type and Location) extract a list of DTS IDs appropriate to User
	vector<int> ids;
	// Use that list of IDs to generate a list of Reports
	// ReportList* x->list is a list of ViewReports
	ReportList* x;
	// i.e.
	x->list[0] = ViewReport(ids[0]);

	/* Call Database Here */

	return x;
}

ReportHistory* DBConn::generateReportHistory(int itemNum, User* curr) {
	// Based on current User (Type and Location) and the Item Number in question
	//	extract a history of Reports that involved that Item Number that the User would need to see
	
	// Extract the DTS IDs that involve the input Item Number
	vector<int> ids;
	// ReportHistory* x->list is a list of ViewReports
	ReportHistory* x;
	// i.e.
	x->list[0] = ViewReport(ids[0]);

	/* Call Database Here */

	return x;
}
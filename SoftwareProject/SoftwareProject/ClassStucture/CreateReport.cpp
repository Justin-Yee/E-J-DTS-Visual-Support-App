#include "CreateReport.h"

CreateReport::CreateReport() {
	// Set Default Values so as to not have Null entries in our Database

	dtsID = 1;
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
	reportStatus = Status::Open;
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

void CreateReport::setStatus(CreateReport::Status st) {
	reportStatus = st;
}

void CreateReport::inputReportInfo() {
	// Use input file or input stream to take in information from user
	// Set class variables to the input

}

void CreateReport::pushToDB() {
	// Use API to apply the insert function to add to the Database

}
#include "ViewReport.h"

ViewReport::ViewReport(int currID) {
	// Extract Report Details from the Database through the API
	
	// Temporary Initializing 
	dtsID = currID;
	workOrderNumber = 123456789;
	materialGroup = "Label";
	defectName = "Splice Issues";
	machineLine = 12;
	incidentDate.tm_mday = 6; // Day of Month
	incidentDate.tm_mon = 11; // Month of Year
	incidentDate.tm_year = 2019; // Year
	incidentClassification = "Hold";
	defectClassification = "Minor";
	defectSeverity = "Operational";
	supplierName = "Corp A";
	itemNumber = 12345;
	causeComment = "Defective Component";
	actionComment = "Return Item(s) to Supplier";
	reportStatus = Status::Open;
}

int ViewReport::getID() {
	return dtsID;
}

int ViewReport::getWON() {
	return workOrderNumber;
}

string ViewReport::getMatGroup() {
	return materialGroup;
}

string ViewReport::getDefName() {
	return defectName;
}

int ViewReport::getMachLine() {
	return machineLine;
}

tm ViewReport::getDate() {
	return incidentDate;
}

string ViewReport::getIncClass() {
	return incidentClassification;
}

string ViewReport::getDefClass() {
	return defectClassification;
}

string ViewReport::getDefSev() {
	return defectSeverity;
}

string ViewReport::getSupplier() {
	return supplierName;
}

int ViewReport::getItemNum() {
	return itemNumber;
}

string ViewReport::getCauseComm() {
	return causeComment;
}

string ViewReport::getActComm() {
	return actionComment;
}

string ViewReport::getStatus() {
	if (reportStatus == Status::Open) {
		return "Open";
	}
	else if (reportStatus == Status::UnderReview) {
		return "Under Review";
	}
	else if (reportStatus == Status::SupplierAction) {
		return "Supplier ";
	}
	else if (reportStatus == Status::Closed) {
		return "Closed";
	}
}

void ViewReport::printBriefReport() {
	// Output of Full Report Information
	cout << "********************" << endl;

	cout << "DTS ID :\t\t" << dtsID << "\t\tWork Order Number : \t\t" << workOrderNumber << endl;
	cout << "Material Group :\t\t" << materialGroup << "\t\tDefect Name :\t\t" << defectName << endl;
	cout << "Current Status :\t\t" << getStatus() << endl;

	cout << "********************" << endl;
}

void ViewReport::printFullReport() {
	// Output of Full Report Information
	cout << "********************" << endl;

	cout << "DTS ID :\t\t" << dtsID << "\t\tWork Order Number : \t\t" << workOrderNumber << endl;
	cout << "Material Group :\t\t" << materialGroup << "\t\tDefect Name \t\t" << defectName << endl;
	cout << "Current Status :\t\t" << getStatus() << endl;
	cout << "Machine Line :\t\t" << machineLine << endl;
	cout << "Incident Date :\t\t" << incidentDate.tm_mon << " " << incidentDate.tm_mday << ", " << incidentDate.tm_year << endl;
	cout << "Incident Classification :\t\t" << incidentClassification << "\t\tDefect Classification :\t\t" << defectClassification << endl;
	cout << "Defect Severity :\t\t" << defectSeverity << endl;
	cout << "Supplier :\t\t" << supplierName << "\t\tItem Number :\t\t" << itemNumber << endl;
	cout << "Suggested Cause :\t\t" << causeComment << endl;
	cout << "Suggested Action :\t\t" << actionComment << endl;

	cout << "********************" << endl;
}
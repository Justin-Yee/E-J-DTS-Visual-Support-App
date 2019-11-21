#include "ViewReport.h"

ViewReport::ViewReport(int currID) {
	// Extract Report Details from the Database through the API
	dtsID = currID;

	ViewReport* x = call.retrieveReportInfo(dtsID);

	workOrderNumber = x->getWON();
	materialGroup = x->getMatGroup();
	defectName = x->getDefName();
	machineLine = x->getMachLine();
	incidentDate.tm_mday = x->getDate().tm_mday;
	incidentDate.tm_mon = x->getDate().tm_mon;
	incidentDate.tm_year = x->getDate().tm_year;
	incidentClassification = x->getIncClass();
	defectClassification = x->getDefClass();
	defectSeverity = x->getDefSev();
	supplierName = x->getSupplier();
	itemNumber = x->getItemNum();
	causeComment = x->getCauseComm();
	actionComment = x->getActComm();
	reportStatus = x->getStatus();
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
	return reportStatus;
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

ViewReport* ViewReport::operator=(ViewReport const& x) {
	ViewReport* y = new ViewReport(x.dtsID);
	return y;
}
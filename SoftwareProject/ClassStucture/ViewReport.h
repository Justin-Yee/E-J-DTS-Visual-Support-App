#pragma once

#include <string>
#include <ctime>

#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;

class ViewReport
{
private:
	enum class Status {Open, UnderReview, SupplierAction, Closed};

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
	Status reportStatus;

public: 

	ViewReport(int currID);

	int getID();
	int getWON();
	string getMatGroup();
	string getDefName();
	int getMachLine();
	tm getDate();
	string getIncClass();
	string getDefClass();
	string getDefSev();
	string getSupplier();
	int getItemNum();
	string getCauseComm();
	string getActComm();
	string getStatus();

	void printBriefReport();
	void printFullReport(); 
};


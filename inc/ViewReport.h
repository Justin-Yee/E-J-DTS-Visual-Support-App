#ifndef TT_VIEWREPORT
#define TT_VIEWREPORT

#include <string>
#include <ctime>
#include "DBConn.h"

using namespace std;
#include <iostream>

class ViewReport
{
public:
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

private:

	DBConn call;

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

	ViewReport* operator=(ViewReport const& x);
};

#endif // !TT_VIEWREPORT
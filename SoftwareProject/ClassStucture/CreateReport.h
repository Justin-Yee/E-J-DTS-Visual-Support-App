#pragma once

#include <string>
#include <ctime>

#include "DBConn.h"

using namespace std;
#include <iostream>

class CreateReport
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

	CreateReport();

	void setID(int id);
	void setWON(int won);
	void setMatGroup(string mat);
	void setDefName(string defName);
	void setMachLine(int machLine);
	void setDate(int day, int month, int year);
	void setIncClass(string incClass);
	void setDefClass(string defClass);
	void setDefSev(string defSev);
	void setSupplier(string supp);
	void setItemNum(int num);
	void setCauseComm(string cause);
	void setActComm(string action);
	void setStatus(string st);

	void inputReportInfo();
	void pushToDB();
};


#pragma once

#include <string>
#include <ctime>

#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;
#include <iostream>

class CreateReport
{
private:
	enum class Status { Open, UnderReview, SupplierAction, Closed };

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
	void setStatus(CreateReport::Status st);

	void inputReportInfo();
	void pushToDB();
};


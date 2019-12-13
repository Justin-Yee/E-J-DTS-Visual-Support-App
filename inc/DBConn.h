#pragma once

// Class to handle API functionality 
// Use this class's methods to access the database 
//		Inserting, Viewing Data, etc.

#include "User.h"
#include "CreateReport.h"
#include "ViewReport.h"
#include "ReportList.h"
#include "ReportHistory.h"

#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
#include <Wt/Dbo/backend/Sqlite3.h> // For specific SQLite3 connection
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class DBConn
{
private:
	
	dbo::Session session;

public:

	DBConn();

	void connect();

	User* retrieveUser(string email);
	void insertReportInfo(CreateReport* ins);
	ViewReport* retrieveReportInfo(int id);

	ReportList* generateReportList(User* curr);
	ReportHistory* generateReportHistory(int itemNum, User* curr);

};


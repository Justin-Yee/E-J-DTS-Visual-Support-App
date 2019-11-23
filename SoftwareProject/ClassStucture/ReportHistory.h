#ifndef TT_REPORTHISTORY
#define TT_REPORTHISTORY

#include "ViewReport.h"
#include "User.h"
#include "DBConn.h"

#include <vector>
#include <string>
#include <ctime>

using namespace std;
#include <iostream>

class ReportHistory
{
public:

	vector<ViewReport> list;

private:
	User* curr;
	int currItem;

	DBConn call;
	
public:

	ReportHistory(int currItemNum, User currUser);

	void printHistory();
};

#endif // !TT_REPORTHISTORY


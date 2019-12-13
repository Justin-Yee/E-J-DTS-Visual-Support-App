#ifndef TT_REPORTLIST
#define TT_REPORTLIST

#include "ViewReport.h"
#include "User.h"
#include "DBConn.h"

#include <vector>
#include <string>
#include <ctime>

using namespace std;
#include <iostream>

class ReportList
{
public:

	vector<ViewReport> list;

private:
	User* curr;

	DBConn call;

public:

	ReportList(User* c);

	void printList();

};

#endif
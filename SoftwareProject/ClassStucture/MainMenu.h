#pragma once

using namespace std;
#include <iostream>
#include <string>

class MainMenu
{
public: 
	enum class Screens
	{
		Main,
		CreateReport,
		ReportList,
		ViewReport,
		ReportHistory,
		About,
		Contact,
		Logout
	};
private:
	Screens current;
	Screens previous[5];
	int index;

public:

	MainMenu();

	void debug(string d);
	void error(string err);
	void displayScreen(Screens s);
	void displayTopBar();
	void displayMain();
	void displayCreate();
	void displayList();
	void displayReport();
	void displayHistory();
	void displayAbout();
	void displayContact();
	void displayLogout();
	void returnToPrior();

};


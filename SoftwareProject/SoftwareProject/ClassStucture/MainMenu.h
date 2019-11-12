#pragma once

using namespace std;
#include <iostream>
#include <string>

class MainMenu
{
private:
	enum class Screens {Main, CreateReport, ReportList, ViewReport, ReportHistory, Logout};
	Screens current;
	Screens previous;

public:

	MainMenu();

	void displayScreen(Screens s);
	void returnToPrior();

};


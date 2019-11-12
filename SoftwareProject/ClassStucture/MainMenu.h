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
	Screens previous;

public:

	MainMenu();

	void displayScreen(Screens s);
	void displayTopBar();
	void returnToPrior();

};


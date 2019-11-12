#include "MainMenu.h"

MainMenu::MainMenu() {
	current = Screens::Main;
	previous = Screens::Main;
}

void MainMenu::displayScreen(Screens s) {
	switch (s)
		case Screens::Main : 
		case Screens::CreateReport : 
		case Screens::ReportList : 
		case Screens::ViewReport : 
		case Screens::ReportHistory : 
		case Screens::About : 
		case Screens::Contact : 
		case Screens::Logout : 
}

void MainMenu::displayTopBar() {
	// Always on the Screen
	// Used to Select another screen
}

void MainMenu::returnToPrior() {
	displayScreen(previous);
}
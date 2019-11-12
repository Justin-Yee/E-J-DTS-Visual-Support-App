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
		case Screens::Logout : 
}

void MainMenu::returnToPrior() {
	displayScreen(previous);
}
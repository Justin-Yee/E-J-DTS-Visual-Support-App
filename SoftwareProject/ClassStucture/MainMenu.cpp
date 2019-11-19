#include "MainMenu.h"

MainMenu::MainMenu() {
	index = 0;
	current = Screens::Main;
	previous[index] = Screens::Main;
}

void MainMenu::debug(string d) {
	cout << "Debug:\t" << d << endl;
}

void MainMenu::error(string err) {
	cout << "Error:\t" << err << endl;
}

void MainMenu::displayScreen(Screens s) {
	if (s == Screens::Main) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayMain();
	}
	else if (s == Screens::CreateReport) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayCreate();
	}
	else if (s == Screens::ReportList) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayList();
	}
	else if (s == Screens::ViewReport) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayReport();
	}
	else if (s == Screens::ReportHistory) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayHistory();
	}
	else if (s == Screens::About) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayAbout();
	}
	else if (s == Screens::Contact) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayContact();
	}
	else if (s == Screens::Logout) {
		index = (index + 1) % 5;
		previous[index] = current;
		current = s;
		displayLogout();
	}
}

void MainMenu::displayTopBar() {
	// Always on the Screen
	// Used to Select another screen

	// Screen Options : Main, List, Contact, Logout
}

void MainMenu::displayMain() {
	
}

void MainMenu::displayCreate() {

}

void MainMenu::displayList() {

}

void MainMenu::displayReport() {

}

void MainMenu::displayHistory() {

}

void MainMenu::displayAbout() {

}

void MainMenu::displayContact() {

}

void MainMenu::displayLogout() {

}

void MainMenu::returnToPrior() {
	if (index == 0) {
		index = 4;
	}
	else {
		index--;
	}
	displayScreen(previous[index]);
}
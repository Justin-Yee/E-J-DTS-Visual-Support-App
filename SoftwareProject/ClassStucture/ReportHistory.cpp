#include "ReportHistory.h"

ReportHistory::ReportHistory(int currItemNum, User currUser) {
	// Import a list of applicable reports based on current User and Item Number
	// User Location and Type determine lists to be viewed 
	// Narrowed down by the Item Number for which we want to view the history

	curr = currUser;
	currItem = currItemNum;
}

void ReportHistory::printHistory() {
	// Iterate over the List and print out the Information we need 
	// I.E. Number of Incidents and When, Supplier of the Item, Machine Line

	cout << "********************" << endl;
	cout << "Item Number :\t\t" << currItem << endl;
	cout << "Supplier :\t\t" << list[0].getSupplier() << "\t\tMachine Line :\t\t" << list[0].getMachLine() << endl;

	// **Iterate Here**

	cout << "********************" << endl;
}
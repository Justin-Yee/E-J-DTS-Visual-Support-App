#include "ReportList.h"

ReportList::ReportList(User* c) {
	// Import a List of applicable reports based on the current User 
	curr = c;
	// User location and type will determine the correct reports to show
	ReportList* x = call.generateReportList(curr);
	list = x->list;
}

void ReportList::printList() {

	// Iterate over list to print Snapshot of each DTS
	for (int i = 0; i < list.size(); i++) {
		list[i].printBriefReport();
	}
}
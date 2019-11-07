#include "ReportList.h"

ReportList::ReportList() {
	// Import a List of applicable reports based on the current User 
	// User location and type will determine the correct reports to show

}

void ReportList::printList() {

	// Iterate over list to print Snapshot of each DTS
	for (int i = 0; i < list.size(); i++) {
		list[i].printBriefReport();
	}
}
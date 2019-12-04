#include <Wt/WText.h>
#include <Wt/WTable>

#include "Reports.h"

using namespace Wt;

WTable *table = this->addWidget(cpp14::make_unique<WTable>());

table->elementAt(0,0)->addWidget(cpp14::make_unique<WText>("Severity"));
table->elementAt(0,1)->addWidget(cpp14::make_unique<WText>("Description"));
table->elementAt(0,2)->addWidget(cpp14::make_unique<WText>("Date"));
table->setHeaderCount(1);

for(int i = 0; i < report.count(); i++){
	int row = table->rowCount();

	table->elementAt(row, 0)->addWidget(cpp14::make_unique<WText>(asString(report.severity)));
	table->elementAt(row, 1)->addWidget(cpp14::make_unique<WText>(asString(report.description)));
	table->elementAt(row, 2)->addWidget(cpp14::make_unique<WText>(asString(report.date)));

}
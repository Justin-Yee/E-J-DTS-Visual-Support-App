#include <Wt/WApplication.h>
#include <Wt/WStandardItemModel.h>
#include <Wt/WTableView.h>

auto tableView = cpp14:: make_unique<WTableView>();
tableView->setModel(csvToModel(WApplication::appRoot() + "table.csv"));


tableView->setColumnResizeEnable(false);
tableView->setColumnAlignment(0,AlignmentFlag::Center);
tableView->setHeaderAlignment(0, AlignmentFlag::Center);
tableView->setAlternatingRowColors(true);
tableView->setRowHeight(35);
tableView->setHeaderHeight(35);
tableView->setSelectionMode(SelectionMode::Single);
tableView->setEditTriggers(EditTrigger::None);

const int WIDTH = 120;
for (int i = 0; i < tableView->model()->columnCount(); ++i)
    tableView->setColumnWidth(i, 120);

//7 px padding on border per column, 2 px border for the table
tableView->setWidth((WIDTH + 7) * tableView->model()->columnCount() + 2);

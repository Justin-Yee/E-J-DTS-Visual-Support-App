#include <Wt/WLineEdit.h>
#include <Wt/WMenu.h>
#include <Wt/WMessageBox.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPopupMenuItem.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <Wt/WContainerWidget.h>


auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>(); //create container

Wt::WNavigationBar *navigation = container->addNew<Wt::WNavigationBar>(); //create a obj in the container for the navigation bar
navigation->setTitle("E. & J. Gallo DTS", "https://www.google.com"); //set the main tittle to go to google when clicked, will change to final websit
navigation->setResponsive(true); //adjusts the size of the navigation bar as the screen size changes

Wt::WStackedWidget *contentsStack = container->addNew<Wt::WStackedWidget>();
contentsStack->addStyleClass("contents");
auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>(ContentsStacked)
auto leftMenu_ = navigation->addMenu(std::move(leftMenu));
//create the tabs for the menubar, left aligned
leftMenu_->addItem("Home", Wt::cpp14::make_unique<Wt::WTextArea>("Home content"));
leftMenu_->addItem("Reports", Wt::cpp14::make_unique<Wt::WTextArea>("Report Content"));
leftMenu_->addItem("Contact", Wt::cpp14::make_unique<Wt::WTextArea>("Contact Content"));
leftMenu_->addItem("About", Wt::cpp14::make_unique<Wt::WTextArea>("About content"));

//create logout button, right aligned
Wt::WPushButton *logoutButton = container->addNew<Wt::WPushButton("Logout");
auto c = container.get();
logoutButton->clicked().connect([=]{
	auto logoutMessage = c->addChild(Wt::cpp14::make_unique<Wt::WMessageBox>("Logout",
																		"<p>Are you sure you want to logout?</p>", Wt::StandardButton::Yes | Wt::StandardButton::No));
	logoutMessage->setModal(false);
	logoutMessage->clicked().connect([=]{
		if(logoutMessage.buttonResult() == Wt::StandardButton::Yes){
			//logout
		}
		else
			c->removeChild(logoutMessage); //get rid of confirmation message
	});

});


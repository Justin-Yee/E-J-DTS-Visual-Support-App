#include "User.h"

User::User(string currEmail) {
	email = currEmail;

	// Extract from Database full info based on email
	User* x = call.retrieveUser(email);

	name = x->getName();
	type = x->getType();
	location = x->getLocation();
		
}

string User::getName() {
	return name;
}

string User::getType() {
	return type;
}

string User::getEmail() {
	return email;
}

string User::getLocation() {
	return location;
}

void User::updateType() {
	// Optional update functionality to alter database info
	// Use API to update the database
}

void User::updateLocation() {
	// Optional update functionality to alter database info
	// Use API to update the database
}

User* User::operator=(User const& x) {
	User* y = new User(x.email);
	return y;
}
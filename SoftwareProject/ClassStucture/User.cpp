#include "User.h"

User::User(string currEmail) {
	email = currEmail;
	// Extract from Database full info based on email
	// Set Name, Type, Email, Location with API
	
	// Temporary default casting
	name = "Bailey Kandler";
	type = Type::Admin;
	location = "Merced";
		
}

string User::getName() {
	return name;
}

string User::getType() {
	if (type == Type::Admin) {
		return "Admin";
	}
	else if (type == Type::Vendor) {
		return "Vendor";
	}
	else if (type == Type::Employee) {
		return "Employee";
	}
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
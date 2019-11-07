#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h> // WebToolKit Connection for API Incorporation with SQL Database
namespace dbo = Wt::Dbo; // For controlling API functionality

using namespace std;

class User
{
private:
	enum class Type { Admin, Vendor, Employee };

	string name;
	Type type;
	string email; 
	string location;

public:

	User();

	string getName();
	string getType();
	string getEmail();
	string getLocation();

	void updateType();
	void updateLocation();
};


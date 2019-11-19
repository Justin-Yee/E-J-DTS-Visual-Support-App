#include "Login.h"

Login::Login() {
	// We would extract from database to get the login info we need
	sample = "username@ejgallo.com";
	database[0] = "kpatel@ejgallo.com";  
	database[1] = "bkandler@ejgallo.com";
	database[2] = "markmcc2950@ejgallo.com";
	database[3] = "jyee@ejgallo.com";
	database[4] = "test@ejgallo.com";
	passwords[0] = "password";
	passwords[1] = "password1";
	passwords[2] = "password2";
	passwords[3] = "password3";
	classification[0] = 2;
	classification[1] = 0;
	classification[2] = 1;
	classification[3] = 1;
	classification[4] = 0;
	validity1 = validity2 = validity3 = false;
}

bool Login::getVal1() {
	return validity1;
}

bool Login::getVal2() {
	return validity2;
}

bool Login::getVal3() {
	return validity3;
}

void Login::error(string err) {
	cout << "ERROR: " << err << endl;
}

void Login::nameCheck(string n) {
	int dbSize = (sizeof(database)) / 32;
	int i = 0;
	int j = 0;
	while (!validity2) {
		int size = database[j].size();
		if (database[j].size() == n.size() && database[j][i] == n[i]) {
			if (n[i] == database[j][i]) {
				i = (i + 1);
				if (i == size - 12) {
					if (!passwords[j].empty()) {
						validity2 = true;
						passCheck(j);
					}
					else {
						error("No matching password in system for username entered.");
					}
				}
			}
		}
		else {
			j++;
			i = 0;
			validity2 = false;
		}
		if (database[j].empty()) {
			error("Empty slot. Username Not Found");
			break;
		}
		if (j >= dbSize) { error("Username Not Found."); break; }
	}
}

void Login::validityCheck(string v) {
	int size = v.size();

	// Check if user name is valid
	if (size > 12) {
		// Check that we have @ejgallo.com at the end (referenced against our sample)
		for (int i = 0; i < 12; i++) {
			if (v[size - 12 + i] != sample[8 + i]) {
				error("Invalid Username.");
				validity1 = false;
				break;
			}
			else {
				validity1 = true;
			}
		}
	}
	else {
		error("Invalid Username.");
		validity1 = false;
	}
}

void Login::passCheck(int n) {
	int index = n;
	string password;
	int i = 0; 
	cout << "Password:\t";
	cin >> password;
	if (password.size() == passwords[index].size()) {
		while (!validity3) {
			// If no password saved, return error. (Shouldn't be able to get here without a password though)
			if (passwords[index].empty()) {
				error("Empty Password Slot. Invalid Username slot.");
				break;
			}
			int size = passwords[index].size();
			if (password[i] == passwords[index][i]) {
				i = (i + 1);
				if (i == size) {
					validity3 = true;
					break;
				}
				else {
					error("Invalid Password.");
					break;
				}
			}
		}
	}
	else {
		error("Ivalid Password.");
	}
}

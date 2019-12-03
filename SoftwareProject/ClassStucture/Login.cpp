#include "Login.h"

Login::Login() {
	// We would extract from database to get the login info we need
	sample = "username@ejgallo.com";
	sampleLng = 0;
	database[0] = "kpatel@ejgallo.com";  
	database[1] = "bkandler@ejgallo.com";
	database[2] = "markmcc2950@ejgallo.com";
	database[3] = "jyee@ejgallo.com";
	database[4] = "test@ejgallo.com";
	passwords[0] = "K;``#DYP";
	passwords[1] = "K;``#DYPO";
	passwords[2] = "K;``#DYPV";
	passwords[3] = "K;``#DYP]";
	classification[0] = 2;
	classification[1] = 0;
	classification[2] = 1;
	classification[3] = 1;
	classification[4] = 0;
	validity1 = validity2 = validity3 = false;
	index = 0;
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

void Login::debug(string d) {
	cout << "DEBUG: " << d << endl;
}

void Login::error(string err) {
	cout << "ERROR: " << err << endl;
}

string Login::affine_encode(string plaintext) {
	int a = 7;
	int b = 23;
	int m = 89;
	// Convert string to const char and find the size
	string text = plaintext.data();
	int size = text.length();
	encoded.resize(size);

	int intText[size];
	int encText[size];

	for (int i = 0; i < size; i++) {
		if (text[i] != ' ') {
			encText[i] = ((((int(text[i]) - 33) * a + b) % m) + 33);
		}
		else {
			encText[i] = text[i];
		}
	}
	char encrypted[size];

	for (int i = 0; i < size; i++) {
		encrypted[i] = char(encText[i]);
		encoded[i] = encrypted[i];
	}

	return encrypted;
}

void Login::nameCheck(string n) {
	int dbSize = (sizeof(database)) / 32;
	int i = 0;
	int j = 0;
	while (!validity2) {
		int size = database[j].size();
		if (database[j].size() == n.size() && database[j][i] == n[i]) {	// Check first if the two string sizes match before progressing
			if (n[i] == database[j][i]) {
				i = (i + 1);
				if (n[i] == '@') {
					if (!passwords[j].empty()) {
						validity2 = true;
						currEmail = database[j];
						index = j;
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
	if (size > sampleLng) {
		// Check that we have @ejgallo.com at the end (referenced against our sample)
		for (int i = 0; i < sampleLng; i++) {
			if (v[size - sampleLng + i] != sample[sample.size() - sampleLng + i]) {
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
		affine_encode(password);												// Encode the password inputted to our global string variable
		password = encoded;														// Save the encoded password to our original variable here
		//debug(password);
		while (!validity3) {
			// If no password saved, return error. (Shouldn't be able to get here without a password though)
			if (passwords[index].empty()) {
				error("Empty Password Slot. Invalid Username slot.");
				break;
			}
			int size = passwords[index].size();
			if (password[i] == passwords[index][i]) {
				i++;
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

void Login::domainLength(string s) {
	int counter = 0;
	bool count = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '@') {
			count = true;
		}
		if (count) {
			counter++;
		}
	}
	sampleLng = counter;
}

void Login::updatePassword(int index, string pass) {
	passwords[index] = pass;
}

string Login::getCurrUser() {
	return currEmail;
}

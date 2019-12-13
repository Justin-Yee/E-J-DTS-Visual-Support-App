#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
/*
	PASSWORDS:
		Passwords stored in array of encrypted passwords
		Each password is stored in the same index value as the username
			If username is index 0, password is also stored in index 0
		User inputs password, which is encrpyted based on something in system exclusive to each user.
		If encrypted password matches value stored in array index, then it's a match
*/

// Global Variables
string sample = "username@ejgallo.com";										// Size is 20, @ is at location 8
int sampleLng;																// Saves the minimum length of the sample (from '@' symbol to end of domain name minimum)
string database[100] =
{ "kpatel@ejgallo.com", "bkandler@ejgallo.com", "markmcc2950@ejgallo.com", "jyee@ejgallo.com", "test@ejgallo.com" };
string passwords[100] =
{ "K;``#DYP", "K;``#DYPO", "K;``#DYPV", "K;``#DYP]" };
// 0 = Admin, 1 = Vendor, 2 = Rest
int classification[100] =
{ 2, 0, 1, 1, 0 };
// String variable for encoding
string encoded;

// Booleans to check for validity of inputs
bool validity1 = false;
bool validity2 = false;
bool validity3 = false;

// Begin code:
//------------------------------------------------------------------------------------------------------------
// Call this with some string to display the debug
void debug(string dbg) {
	cout << "DEBUG: " << dbg << endl;
}

// Call this with some string to display the error
void error(string err) {
	cout << "ERROR: " << err << endl;
}

// For encoding passwords to not be stored in plaintext (a = 7, b = 23, m = 89)
string affine_encode(string plaintext) {
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

void passCheck(int n) {
	int index = n;
	string password;
	int i = 0;
	cout << "Password:\t";
	cin >> password;
	if (password.size() == passwords[index].size()) {
		affine_encode(password);												// Encode the password inputted to our global string variable
		password = encoded;														// Save the encoded password to our original variable here
		debug(password);														// Allows us to see what the password was encrypted to if it doesn't match what's in the file
		while (!validity3) {
			// If no password saved, return error. (Shouldn't be able to get here without a password though)
			if (passwords[index].empty()) {
				error("Empty password slot. Invalid username slot.");
				break;
			}
			int size = passwords[index].size();

			if (password[i] == passwords[index][i]) {							// If the first letter of the passwords match, progres on
				i++;
				if (i == size) {												// If we reach the size of the password stored, then we have confirmation
					validity3 = true;
					break;
				}
			}
			else {
				error("Invalid password.");										// Inputted password doesn't match
				break;
			}
		}
	}
	else {
		error("Invalid password.");
	}

}

// Checks if the actual username itself is stored in the system
void nameCheck(string n) {
	int dbSize = (sizeof(database)) / 32;										// Size of the entire array of usernames
	bool check = true;
	int i = 0;
	int j = 0;
	while (!validity2) {
		int size = database[j].size();
		if (database[j].size() == n.size() && database[j][i] == n[i]) {			// Check first if the two string sizes match before progressing
			if (n[i] == database[j][i]) {										// Check if each letter of the two strings match in order
				i = (i + 1);
				if (n[i] == '@') {												// If we reach the '@' symbol, stop searching. Username is verified
					if (!passwords[j].empty()) {								// If the corresponding password array index is populated, this is a valid username
						validity2 = true;
						passCheck(j);
					}
					else {														// No matching password found for the inputted username
						error("No matching password in system for username entered.");
						break;
					}
				}
			}
		}
		else {
			j++;																// Parse to the next index value
			i = 0;																// Reset i to zero to begin looking at the first letter again
			validity2 = false;													// Validity2 is false until all values match
		}
		// If we reach an empty index of the database that's yet to be assigned a username, exit the program.
		if (database[j].empty()) {
			error("Username Not Found");
			break;
		}
		if (j >= dbSize) { error("Username Not Found."); break; }
	}
}

// Checks if the username is valid first (Includes @ejgallo.com for initial check)
void validityCheck(string v) {
	int size = v.size();
	// Check if user name is valid
	if (size > sampleLng) {
		// Check that we have @[domain] at the end (referenced against our sample)
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

// Gives us the length of the sample starting from the  '@' symbol in the domain name
void domainLength(string s) {
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

int main(void) {
	domainLength(sample);																// Get the value minimum username length
	//// Encrypt Passwords for testing purposes
	//for (int i = 0; i < passwords->size(); i++) {
	//	// If we reach an empty index, stop searching
	//	if (passwords[i].empty()) {
	//		break;
	//	}
	//	else {
	//		affine_encode(passwords[i]);										// Encode the passwords
	//		passwords[i] = encoded;												// Save the new passwords into the original array
	//		debug(passwords[i]);												// Debug way to verify encoded passwords match what we have in system
	//	}
	//}

	string userName;
	int errCtr = 0;																// Allows a certain amount of invalid usernames before terminating
	bool nameVerify = true;														// Small loop to input username as valid
	while (!validity1 && errCtr <= 5) {
		cout << "Username:\t";
		cin >> userName;

		if (userName.size() > sampleLng && !userName.empty()) {
			validityCheck(userName);
			if (validity1) nameCheck(userName);
		}
		if (!validity1) {
			errCtr++;
			if (errCtr >= 5) {
				error("Invalid username.");
			}
		}
	}


	if (validity1 && validity2 && validity3) {
		cout << "Success!" << endl;
	}
}
//------------------------------------------------------------------------------------------------------------
// End code
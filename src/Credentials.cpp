#include "Credentials.h"

Credentials::Credentials() {
	currUserIndex = 0;
}

void Credentials::setIndex(int i) {
	currUserIndex = i;
}

int Credentials::getIndex() {
	return currUserIndex;
}
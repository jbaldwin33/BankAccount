#include "Bank.h"

Bank::Bank() {
	open = false;
	numOfAccounts = 0;
}

bool Bank::isOpen() {
	return open;
}

void Bank::setIsOpen(bool b) {
	open = b;
}

void Bank::AddAccount() {
	numOfAccounts++;
}

void Bank::RemoveAccount() {
	numOfAccounts--;
}

void Bank::CloseBank() {
	open = false;
	numOfAccounts = 0;
}

int Bank::getNumOfAccounts() {
	return numOfAccounts;
}

void Bank::setNumOfAccounts(int x) {
	numOfAccounts = x;
}
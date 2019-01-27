#include "Helper.h"
#include <iostream>

Account* checkAccount(std::vector<Account>& accounts, int acct) {

	for (int i = 0; i < accounts.size(); i++) {
		if (acct == accounts[i].getNum()) {
			return &accounts[i];
		}
	}
	return nullptr;
}

bool pinCheck(Account* a) {
	std::string input;
	std::cout << "Pin number: ";
	std::cin >> input;
	if (input == a->getPin()) {
		return true;
	}
	else {
		return false;
	}
}
#include "Helper.h"
#include "Bank.h"
#include <iostream>
#include <ctime>

using namespace std;

#define MAX_ACC 10
#define INTEREST 0.10
#define ADMIN_PIN "0909"



int main() {
	srand(time(NULL));
	vector<Account> accounts;
	string pin;
	string admin;
	float initdep;
	int newNum;
	char types;
	Bank bank = Bank();
	Account* user;
	int acct;
	int pos = 0;
	int tries;
	while (true) {
		cout << "Transaction type?: ";
		cin >> types;
		switch (types) {
		case 'S':
			cout << "Pin number: ";
			cin >> admin;
			if (admin == ADMIN_PIN) {
				if (bank.isOpen()) {
					cout << "Bank is already open." << endl;
				}
				else {
					bank.setIsOpen(true);
					cout << "Bank is now open." << endl;
				}
			}
			else {
				cout << "Incorrect." << endl;
			}
			break;

		case 'O':
			if (bank.isOpen()) {
				if (accounts.size() < MAX_ACC) {
					bool safe = false;
					cout << "Choose a pin number: ";
					cin >> pin;
					cout << "Initial amount?: ";
					cin >> initdep;
					Account a1(pin, initdep);
					newNum = rand() % (10 - 1 + 1) + 1;
					for (Account a : accounts) {
						if (newNum == a.getNum()) {
							safe = false;
							newNum = rand() % (10 - 1 + 1) + 1;
						}
						else {
							safe = true;
							break;
						}
					}
					a1.setNum(newNum);
					accounts.push_back(a1);
					cout << "Account number: " << a1.getNum() << endl;
					cout << "Pin is " << a1.getPin() << endl;
					printf("Balance: $%4.2f\n", a1.getBalance());
					cout << "Number of accounts: " << accounts.size() << endl << endl;
				}
				else {
					cout << "Too many accounts." << '\n';
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'B':
			if (bank.isOpen()) {
				tries = 0;
				cout << "Account number?: ";
				cin >> acct;

				user = checkAccount(accounts, acct);
				if (user == nullptr) {
					cout << "No account found." << '\n';
				}
				else {
					while (tries < 3) {
						if (pinCheck(user)) {
							cout << "Account number: " << user->getNum() << '\n';
							cout << "Pin is " << user->getPin() << endl;
							printf("Balance: $%4.2f\n", user->getBalance());
							break;
						}
						else {
							tries++;
							if (tries < 3) {
								cout << "Invalid pin, try again.(" << (3 - tries) << " remaining.)" << endl;
							}
						}
					}
					if (tries == 3) {
						cout << "Account locked." << endl;
					}
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'D':
			if (bank.isOpen()) {
				tries = 0;
				float deposit;
				cout << "Account number?: ";
				cin >> acct;
				user = checkAccount(accounts, acct);
				if (user == nullptr) {
					cout << "No account found." << '\n';
				}
				else {
					while (tries < 3) {
						if (pinCheck(user)) {
							cout << "How much would you like to deposit?: ";
							cin >> deposit;
							user->setBalance(user->getBalance() + deposit);
							cout << "Account number: " << user->getNum() << '\n';
							printf("Balance: $%4.2f\n", user->getBalance());
							break;
						}
						else {
							tries++;
							cout << "Invalid pin, try again.(" << (3 - tries) << " remaining.)" << endl;
						}
					}
					if (tries == 3) {
						cout << "Account locked." << endl;
					}

				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'W':
			if (bank.isOpen()) {
				tries = 0;
				float withdraw;
				cout << "Account number?: ";
				cin >> acct;
				user = checkAccount(accounts, acct);
				if (user == nullptr) {
					cout << "No account found." << '\n';
				}
				else {
					while (tries < 3) {
						if (pinCheck(user)) {
							cout << "How much to withdraw? ";
							cin >> withdraw;
							cout << "Try to withdraw $" << withdraw << " from $" << user->getBalance() << endl;
							if (withdraw <= user->getBalance()) {
								printf("Old balance is $%4.2f\n", user->getBalance());
								user->setBalance(user->getBalance() - withdraw);
								printf("New balance is $%4.2f\n", user->getBalance());
							}
							else {
								cout << "Insuffucient funds.\n";
							}
							cout << "Account number: " << user->getNum() << '\n';
							printf("Balance: $%4.2f\n", user->getBalance());
							break;
						}
						else {
							tries++;
							cout << "Invalid pin, try again.(" << (3 - tries) << " remaining.)" << endl;
						}
					}
					if (tries == 3) {
						cout << "Account locked." << endl;
					}
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'C':
			if (bank.isOpen()) {
				tries = 0;
				cout << "Account number?: ";
				cin >> acct;
				user = checkAccount(accounts, acct);
				if (user == nullptr) {
					cout << "No account found." << '\n';
				}
				else {
					while (tries < 3) {
						if (pinCheck(user)) {
							for (Account a : accounts) {
								if (acct == a.getNum()) {
									break;
								}
								else {
									pos++;
								}
							}
							accounts.erase(accounts.begin() + pos);
							cout << "Account deleted.\n";
							cout << "Number of accounts: " << accounts.size() << endl;
							break;
						}
						else {
							tries++;
							cout << "Invalid pin, try again.(" << (3 - tries) << " remaining.)" << endl;
						}
					}
					if (tries == 3) {
						cout << "Account locked." << endl;
					}
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'I':
			if (bank.isOpen()) {
				cout << "Pin number: ";
				cin >> admin;
				if (admin == ADMIN_PIN) {
					for (int i = 0; i < accounts.size(); i++) {
						accounts[i].setBalance(accounts[i].getBalance() + (accounts[i].getBalance() * INTEREST));
						cout << "Interest applied." << endl;
					}
				}
				else {
					cout << "Incorrect." << endl;
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'P':
			if (bank.isOpen()) {
				cout << "Pin number: ";
				cin >> admin;
				if (admin == ADMIN_PIN) {
					cout << "There are " << accounts.size() << " accounts." << endl;
					cout << endl;
					for (Account a : accounts) {
						printf("Account #%x has $%4.2f\n", a.getNum(), a.getBalance());
						cout << "Pin is " << a.getPin() << "." << endl;
					}
				}
				else {
					cout << "Incorrect." << endl;
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'E':
			if (bank.isOpen()) {
				cout << "Pin number: ";
				cin >> admin;
				if (admin == ADMIN_PIN) {
					accounts.clear();
					cout << "All accounts have been deleted." << endl;
				}
				else {
					cout << "Incorrect." << endl;
				}
			}
			else {
				cout << "Bank is not open." << endl;
			}
			break;

		case 'Q':
			return 0;

		default:
			cout << "Use O, B, D, W, C, I, P, E, S, or Q" << endl;
			break;

		}
	}

	//cin.get();
	//cin.get();
	return 0;
}


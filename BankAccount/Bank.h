#include "Account.h"


class Bank {
private:
	bool open;
	int numOfAccounts;

public:
	Bank();
	bool isOpen();
	void setIsOpen(bool b);
	void AddAccount();
	void RemoveAccount();
	void CloseBank();
	int getNumOfAccounts();
	void setNumOfAccounts(int x);

};
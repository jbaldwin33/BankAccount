#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
	int num;
	std::string pin;
	float balance;

public:
	Account();
	Account(std::string p, float b);
	Account(int a, std::string p, float b);

	int getNum();
	float getBalance();
	std::string getPin();
	void setNum(int _num);
	void setBalance(float _balance);
	void setPin(std::string _pin);
};

#endif
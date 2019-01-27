#include "Account.h"

Account::Account() {
	num = 0;
	pin = "0000";
	balance = 0.0;
}
Account::Account(std::string p, float b) {
	pin = p;
	balance = b;
}
Account::Account(int a, std::string p, float b) {
	num = a;
	pin = p;
	balance = b;
}

int Account::getNum() {
	return num;
}
float Account::getBalance() {
	return balance;
}
std::string Account::getPin() {
	return this->pin;
}
void Account::setNum(int _num) {
	num = _num;
}
void Account::setBalance(float _balance) {
	balance = _balance;
}
void Account::setPin(std::string _pin) {
	pin = _pin;
}
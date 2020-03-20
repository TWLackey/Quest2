#include <iostream>
#include "account.h"

bool account::pay_in(float value) {
	if (value < 0) {
		return false;
	}
	else
		balance += value;
	return true;
}

bool account::pay_out(float value) {
	if (value < 0) {
		return false;
	}
	else
		balance -= value;
	return true;
}

int account::getID() {

	return id;

}

int account::getPin() {

	return pin;

}

void account::display_balance(){

		std::cout << "Balance: $" << balance;
		std::cout << std::endl;
}
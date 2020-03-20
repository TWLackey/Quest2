#ifndef ACCOUNT_H
#define ACCOUNT_H

class account {

	int id;
	int pin;
	float balance;

public:

	//default constructor 
	account() : balance(0.0f) {

	}

	// conversion constuctor
	account(float value, int _id, int _pin) {
		balance = value;
		pin = _pin;
		id = _id;
	}

	bool pay_in(float value);

	bool pay_out(float value);

	int getID(); 

	int getPin(); 

	void display_balance(); 
};


#endif // !ACCOUNT_H

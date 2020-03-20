#include <iostream>
#include "account.h"
#include "interaction.h"

using namespace std;


int main() {

	database db;

	account account1(650.0, 0001, 1234),
		account2(500.0, 0002, 1234);

	db.append(account1);
	db.append(account2);

	char userCommand;
	cout << "Please [L]ogin or [C]reate an account (deposit required):";
	cin >> userCommand;
	cout << endl;

	switch (userCommand) {

	case 'C':
		createAccount(db);
		cout << "Now Please login to your new acccount." << endl;
		login(db);
		break;

	case 'L':
		login(db);
		break;
	}

	cin.get();
	return 0;
}
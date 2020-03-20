#include <iostream>
#include "interaction.h" 
using namespace std;


void menu(database& db, int accountID) {

	system("cls");
	cout << "Choose an option:" << endl << "[B]alance" << endl;
	cout << "[T]ransfer" << endl << "[L]ogout" << endl << "[E]xit" << endl;

	char command;
	char userCommand;
	std::cin >> command;


	switch (command)
	{
	case 'B':
		system("cls");

		db.find(accountID).display_balance();
		 
		char enter; 
		cout << "Enter any character to continue" << endl;
		cin >> enter;

		menu(db, accountID);
		break;
	case 'T':
		system("cls");

		int transferID;
		cout << "Enter account ID to transfer to: ";
		cin >> transferID; 
		if (db.find(transferID).getID() == transferID) {
			float amount = 0.0;
			cout << "Enter an amount to transfer: ";
			cin >> amount;

			transfer(db, accountID, transferID, amount);

		}

		cout << "Account #" << accountID << " ";
		db.find(accountID).display_balance();
		cout << endl << "Account #" << transferID << " ";
		db.find(transferID).display_balance();
		cout << endl;

		cout << "Enter any character to continue" << endl;
		cin >> enter;

		menu(db, accountID);

		break;
	case 'L':

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

		break;
	case 'E':
		cout << "Ending Program" << endl;
		break;
	default:
		cout << "Please select an option";
		menu(db, accountID);
	}
}

void login(database& db){
	system("cls");

	int userID;
	cout << "Enter Account ID:" << endl;
	cin >> userID;

	if (db.find(userID).getID() == userID) {
		int userPin;
		cout << "Enter Pin: ";
		cin >> userPin;
		if (db.find(userID).getPin() == userPin) {
			menu(db, userID);
		}
	}
	else {
		login(db);
	}
}


void transfer(database& db, int account1ID, int account2ID, const float& amount) {
	db.find(account1ID).pay_out(amount);
	db.find(account2ID).pay_in(amount);
}

void createAccount(database& db) {
	system("cls");
	int userID = 0;
	cout << "Create an ID: ";
	cin >> userID;

	int userPIN;
	cout << endl << "Create a PIN: ";
	cin >> userPIN;

	int userBalance = 0.0f;
	cout << endl << "Enter your starting balance: $";
	cin >> userBalance;

	account newAccount(userBalance, userID, userPIN);
	db.append(newAccount);

}
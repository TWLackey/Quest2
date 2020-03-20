#ifndef INTERACTION_H
#define INTERACTION_H
#include "account.h"
#include "database.h"

using namespace std;

void transfer(database& db, int account1ID, int account2ID, const float& amount);

void login(database& db);

void menu(database& db, int accountID);

void createAccount(database& db);

#endif // !INTERACTION_H
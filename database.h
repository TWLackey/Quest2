#ifndef DATABASE_H
#define DATABASE_H
#include "account.h"
#include <vector>

class database {

public:

	database() {

	}

	void append(const account& a) {
		accounts.push_back(a);
	}

	account& find(int userID);

private:
	std::vector <account> accounts;
};


#endif // !DATABASE_H
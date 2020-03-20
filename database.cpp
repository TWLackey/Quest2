#include "database.h"

using namespace std; 


account& database::find(int userID) {
	account a; 
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).getID() == userID) {
			return accounts.at(i);
		}
	}
	return a;
}

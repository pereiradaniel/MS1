#include <iostream>
#include <cstring>
using namespace std;
#include "Utils.h"

namespace sdds {
	void Utils::read(int& val, int min, int max, const char* ErrorMess) {
		bool ok;
		char newline;
		const char* orgMes = ErrorMess;
		const char invalidInt[] = "Invalid Integer, try again: ";
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
				ErrorMess = invalidInt;
			}
			else {
				ok = val <= max && val >= min;
				ErrorMess = orgMes;
			}
		} while (!ok && cout << ErrorMess);
	}
}
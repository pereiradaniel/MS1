#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	

	// MenuItem Class
	/////////////////

	MenuItem::MenuItem(const char* value) : m_value(nullptr) {
		// if the value is not nullptr, then allocate memory and do strcpy()
		const int length = strlen(value);
		char* newValue = new char[length + 1];
		if (value != nullptr) {
			strcpy(m_value, newValue);
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_value;
	}

	void MenuItem::display() const {
		// if the m_value is not nullptr, then output m_value and endl
		if (m_value != nullptr) {
			cout << m_value << endl;
		}
	}


	// Private Methods
	//////////////////

	void Menu::indent() const {
		// output 4 spaces in a loop (from 0 to m_indentation)
		for (int i = 0; i < m_indentation; i++) {
			cout << " ";
		}
	}

	void Menu::clear() {
		// deallocate all the menu items in a loop.
		for (int i = 0; i < m_noOfItems; i++) {
			delete[] m_items[i];
		}
	}

}
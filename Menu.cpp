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
			strcpy(m_value, value);
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_value;
	}

	void MenuItem::display() const {
		// if the m_value is not nullptr, then output m_value and endl
	}


	// Private Methods
	//////////////////

	void Menu::indent() const {

	}

}
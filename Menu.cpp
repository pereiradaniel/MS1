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
			cout << "    ";
		}
	}

	void Menu::clear() {
		// deallocate all the menu items in a loop.
		// deallocate m_title
		// after delete or delete[] it is recommended to put nullptr in the pointer
		// set up zero number of items
		for (int i = 0; i < m_noOfItems; i++) {
			delete m_items[i];
		}
		delete[] m_title;
		m_title = nullptr;
		m_items[0];
	}


	// Constructors, Copy Constructor, Assignments(2), Destructor

	Menu::Menu(const char* title, int indentation) :
		m_title(nullptr),
		m_items{ nullptr },
		m_noOfItems(0),
		m_indentation(indentation) {
		*this = title;
	}

	Menu::Menu(const Menu& M) :
		m_title(nullptr),
		m_items{ nullptr },
		m_noOfItems(0),
		m_indentation(M.m_indentation) {
		*this = M; 
	}

	Menu& Menu::operator=(const char* title) {
		// check the title parameter
		// if it is not nullptr
		if (title != nullptr) {
			// delete the old title
			delete[] this->m_title;
			// allocate a new memory
			int length = strlen(title);
			this->m_title = new char[length + 1];
			// do strcpy()
			strcpy(this->m_title, title);
		}
		else {
			// otherwise title is nullptr
			this->m_title = nullptr;
		}
		return *this;
	}

	Menu& Menu::operator=(const Menu& M) {
		// check if 2 objects are the same, if they are, nothing to do
		if (this != &M) {
			// call clear() on the current object
			this->clear();

			// if M is not empty
			if (M.isEmpty() == false) {
				//	a - replace the menu title (you can reuse the assignment oprator)
				*this = M.m_title;
				//	b - add to the current menu all the menu items from M in a loop
				for (int i = 0; i < M.m_noOfItems; i++) {
					add(M.m_items[i]->m_value);
				}
				// copy indentation from M to the current object
				this->m_indentation = M.m_indentation;
			}
		}
		return *this;
	}

	Menu::~Menu() {
		clear();
	}

	// Add function and insertion function

	void Menu::add(const char* item) {
		// check if your menu is not empty and number of items is leess than MAX_NO_OF_ITEMS
		// if any of that then nothing to do
		
		// check item parameter

	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	// MenuItem Class

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
		if (!isEmpty && m_noOfItems < MAX_NO_OF_ITEMS) {
			// check item parameter
			if (item != nullptr) {
				// if it is not nullptr
				// create a new menu item and add it to array of items
				MenuItem newItem(item);
				this->add(item);
				// increase the number of items
				m_noOfItems += 1;
			}
			else {
				// if the item parameter is nullptr, call clear() on the current menu
				clear();
			}			
		}

	}

	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}


	// display menu function
	void Menu::display() const {
		// if the menu is empty, just print a message "Invalid Menu!" and end of line otherwise:
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			//	call indent() function
			indent();
			//	print the m_title and end of line
			cout << m_title << endl;
			//	if there is no items, print a message "No Items to display!" and end of line
			if (m_items == nullptr) {
				cout << "No Items to display!" << endl;
			}
			else {
				//	if theere are items, in a loop call indent(), print menu item number, dash, space
				//  call display() for each item
				//		m_items[i]->display();
				for (int i = 0; i < m_noOfItems; i++) {
					indent();
					cout << i + "- ";
					m_items[i]->display();
				}
				
				//	after the loop call indent() and print a prompt character and a space
				indent();
				cout << "> ";
			}
		}
	}

	// casting
	Menu::operator int() const {
		return run();
	}

	Menu::operator bool() const {
		return !isEmpty();
	}

	bool Menu::isEmpty() const {
		return (m_title == nullptr);
	}

	// run
	int Menu::run() const {
		int selection = 0;
		display();
		if (!isEmpty() && m_noOfItems > 0)
			Utils::read(selection, 1, m_noOfItems, "Invalid selection, try again: ");
	}
}


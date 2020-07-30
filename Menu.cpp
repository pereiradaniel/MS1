#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    // MenuItem

    MenuItem::MenuItem(const char* value) : m_value(nullptr) {
        m_value = new char[strlen(value) + 1];
        strcpy(m_value, value);
    }

    MenuItem::~MenuItem() {
        delete[] m_value;
        m_value = nullptr;
    }

    void MenuItem::display() const {
        if (m_value != nullptr)
            cout << m_value << endl;
    }


    // Menu

    Menu::Menu() {
        m_title = nullptr;
        m_item[0] = nullptr;
        m_noOfItems = 0;
        m_indentation = 0;
    }

    Menu::Menu(const char* title, int indentation) :
        m_title(nullptr),
        m_item{ nullptr },
        m_noOfItems(0),
        m_indentation(indentation) {
        *this = title;
    }

    Menu::~Menu() {
        clear();
    }

    Menu::Menu(const Menu& M) :
        m_title(nullptr),
        m_item{ nullptr },
        m_noOfItems(0),
        m_indentation(M.m_indentation) {
        *this = M;
    }

    Menu& Menu::operator=(const Menu& new_menu) {
        // Check if this menu is same as new menu
        if (this != &new_menu) {
            clear();
            // Add values to menu
            m_noOfItems = new_menu.m_noOfItems;
            m_indentation = new_menu.m_indentation;
            
            if (new_menu.m_title != nullptr) {
                // Handle title
                m_title = new char[strlen(new_menu.m_title) + 1];
                strcpy(m_title, new_menu.m_title);
                // Handle menu items
                int counter = new_menu.m_noOfItems;
                for (int i = 0; i < counter; i++) {
                    m_item[i] = new MenuItem(new_menu.m_item[i]->m_value);
                }
            }
            else {
                clear();
            }
        }
        return *this;
    }

    const Menu& Menu::operator=(const char* title) {
        // check the title parameter
        // if it is not nullptr
        if (title != nullptr) {
            // delete the old title
            delete[] m_title;
            // allocate a new memory
            m_title = new char[strlen(title) + 1];
            // do strcpy()
            strcpy(m_title, title);
        }
        else {
            m_title = nullptr;
        }
        return *this;
    }

    Menu::operator bool() const {
        return m_indentation >= 0 && m_title != nullptr
            && m_noOfItems > 0 && m_noOfItems <= MAX_NO_OF_ITEMS;
    }

    bool Menu::isEmpty() const {
        return !(*this);
    }

    void Menu::display() const {
        // if the menu is empty, just print a message "Invalid Menu!" and end of line otherwise:
        if (m_title == nullptr) {
            cout << "Invalid Menu!" << endl;
        }
        else {
            //	call indent() function
            indent();
            //	print the m_title and end of line
            cout << m_title << endl;
            //	if there is no items, print a message "No Items to display!" and end of line
            if (isEmpty()) {
                cout << "No Items to display!" << endl;
            }
            else if (!isEmpty()) {
                //	if there are items, in a loop call indent(), print menu item number, dash, space
                //  call display() for each item
                //		m_items[i]->display();
                for (int i = 0; i < m_noOfItems; i++) {
                    indent();
                    cout << i + 1 << "- ";
                    m_item[i]->display();
                }

                //	after the loop call indent() and print a prompt character and a space
                indent();
                cout << "> ";
            }
        }
    }

    void Menu::indent() const {
        // output 4 spaces in a loop (from 0 to m_indentation)
        for (int i = 0; i < m_indentation; i++) {
            cout << "    ";
        }
    }

    void Menu::add(const char* newItem) {
        if (newItem != nullptr) {
            m_item[m_noOfItems] = new MenuItem(newItem);
            m_noOfItems++;
        }
        else {
            clear();
        }
    }

    Menu& Menu::operator<<(const char* newContent) {
        add(newContent);
        return *this;
    }

    int Menu::run() const {
        int selection = 0;
        display();
        if (!isEmpty() && m_noOfItems > 0)
            Utils::read(selection, 1, m_noOfItems, "Invalid selection, try again: ");
        return selection;
    }

    Menu::operator int() const {
        return run();
    }

    void Menu::clear() {
        delete[] m_title;
        for (int i = 0; i < m_noOfItems; ++i) {
            delete m_item[i];
            m_item[i] = nullptr;
        }
        m_title = nullptr;
        m_indentation = 0;
        m_noOfItems = 0;
    }
}

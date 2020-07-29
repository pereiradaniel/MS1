#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;

	class MenuItem {
	private:
		char* m_value;
	public:
		MenuItem(const char* value);
		MenuItem(const MenuItem& mi) = delete;				// No copy constructor!
		MenuItem& operator=(const MenuItem& mi) = delete;	// No assignment!
		~MenuItem();
		void display() const;
		friend class Menu;		// Establish friendship between Menu and MenuItem.
	};

	class Menu {
	private:
		char*		m_title;
		MenuItem*	m_items[MAX_NO_OF_ITEMS];
		int			m_noOfItems;
		int			m_indentation;	// 0 - 0 spaces, 1 - 4 spaces etc.
		void		indent() const;
		void		clear();
	public:
		Menu(const char* title, int indentation = 0);
		Menu(const Menu&);
		Menu& operator=(const Menu&);
		Menu& operator=(const char* title);
		~Menu();
		void add(const char* item);
		Menu& operator<<(const char* item);
		void display() const;
		operator int() const;
		operator bool() const;
		bool isEmpty() const;
		int run() const;
	};
}

#endif
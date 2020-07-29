#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
	const unsigned int ReadBufferSize = 40;
	struct Utils {
		static void read(int& val, int min, int max, const char* errorMessage = "");
	};
}
#endif
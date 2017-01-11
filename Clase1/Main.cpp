
#include <iostream>
#include "Timer.h"

int main() {
	//Timer t1 = Timer::getInstance();
	Timer &t1 = Timer::getInstance();
	std::cout << t1.getTime() << std::endl;
	return 0;
}

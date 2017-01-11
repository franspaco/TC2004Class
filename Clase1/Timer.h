#pragma once
#include <ctime>

class Timer {
private:
	Timer() {}
	Timer(Timer const&);
	void operator=(Timer const&);
public:
	static Timer& getInstance() {
		static Timer instance;
		return instance;
	}

	time_t getTime() {
		return time(0);
	}
};

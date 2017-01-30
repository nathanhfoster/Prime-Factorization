#ifndef WATCH_HPP
#define WATCH_HPP
#include<iostream>
#include <chrono> // Time
#include <thread> // Sleep

template<typename TimeT = std::chrono::microseconds,
	typename ClockT = std::chrono::high_resolution_clock,
	typename DurationT = double>
	class Watch
{
private:
	std::chrono::time_point<ClockT> _start, _end;
public:
	Watch() { start(); }
	void start() { _start = _end = ClockT::now(); }
	void sleep(int t) { std::this_thread::sleep_for(std::chrono::milliseconds(t)); }
	DurationT stop() { _end = ClockT::now(); return elapsed(); }
	DurationT elapsed() {
		auto delta = std::chrono::duration_cast<TimeT>(_end - _start);
		return delta.count();
	}
};
#endif
// std::this_thread::sleep_for(std::chrono::milliseconds(5000));
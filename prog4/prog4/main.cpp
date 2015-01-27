#include <deque>
#include <iostream>
#include <ctime>
#include "queue.h"
#include <array>


template<typename QueueType>
void time_queue(QueueType test_queue, const std::string queue_name)
{
	clock_t timer = clock();

	std::cout << queue_name << ": ";
	const long long num1 = 1000000, num2 = 100 * num1;

	for (int i = 1; i < num1; ++i) {
		test_queue.push_back(i);
	}
	for (int i = 1; i < num2; ++i) {
		test_queue.push_back(i);
		test_queue.pop_front();
	}
	for (int i = 1; i < num1; ++i) {
		test_queue.pop_front();
	}
	timer = clock() - timer;
	std::cout << 2 * (num1 + num2) << " queue operations took "
		<< static_cast<double>(timer) / CLOCKS_PER_SEC << " seconds.\n";
}


int main()
{
	struct Test{ std::array<int, 4> j; Test(int i){} };
	std::deque<Test> q2;
	time_queue(q2, "std::deque<int>");
	Queue<Test> q1;
	time_queue(q1, "Queue<int>");
}

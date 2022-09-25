#include <ctime>
#include "../include/QueueAnalyzer.h"

int main()
{
	QueueAnalyzer<int> analyze;
	analyze.generate(10);

	analyze.add(12);
	analyze.erase(0);

	std::cout << "Value 12 : [" << analyze.find(12) << "]\n";

	analyze.printData();
	std::cout << "\n";

	analyze.sort();

	analyze.printData();
	std::cout << "\n";

	analyze.clear();
	analyze.printData();
	std::cout << "\n";

	return 0;
}

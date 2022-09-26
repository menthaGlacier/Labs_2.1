#include "../include/QueueAnalyzer.h"

int main()
{
	QueueAnalyzer<int> analyze;

	analyze.run(10, 4000);
	return 0;
}

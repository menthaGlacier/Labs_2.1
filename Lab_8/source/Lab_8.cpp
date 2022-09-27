#include "../include/QueueAnalyzer.h"
#include "../include/SetAnalyzer.h"

int main()
{
	QueueAnalyzer<int> q_analyze;

	q_analyze.run(10, 4000);

	SetAnalyzer<int> s_analyze;

	s_analyze.run(10, 4000);
	return 0;
}

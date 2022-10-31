bool SHOW_TRACE = true;

#include "../include/QueueAnalyzer.h"
#include "../include/SetAnalyzer.h"

int main(int argc, char* argv[])
{
	if (argc > 1) 
	{
		for (int i = 1; i < argc; i++)
		{
			if (argv[i][0] == 'n' && argv[i][1] == 't') 
			{
				SHOW_TRACE = false;
				break;
			}
		}
	}

	QueueAnalyzer<int> q_analyze;

	q_analyze.run(10, 4000);

	SetAnalyzer<int> s_analyze;

	s_analyze.run(10, 4000);
	return 0;
}

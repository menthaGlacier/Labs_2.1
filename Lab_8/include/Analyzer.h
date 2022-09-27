#ifndef ANALYZER_H
#define ANALYZER_H

#include "pch.h"

template<class T>
class Analyzer
{
public:	
	virtual ~Analyzer() {};

	virtual void generate(size_t amount) = 0;
	virtual void add(const T& element) = 0;
	virtual	void clear() = 0;
	virtual void erase(size_t index) = 0;
	virtual int find(const T& value) = 0;
	virtual void sort() = 0;
	virtual void printData() = 0;

	void run(size_t repeats, size_t data_size)
	{
		if (!(repeats && data_size)) { return; }

		TimeResults gen_TR, add_TR, erase_TR, find_TR, sort_TR, clear_TR;

		for (size_t r = 0; r < repeats; r++)
		{
			std::cout << "\nIteration " << r << std::flush;
			generate(data_size);
			calculateTimeResult(gen_TR, getLastTime(), r);
			std::cout << " generated" << std::flush;

			T new_value = rand();
			add(new_value);
			calculateTimeResult(add_TR, getLastTime(), r);
			std::cout << ", added value" << std::flush;

			erase(0);
			calculateTimeResult(erase_TR, getLastTime(), r);
			std::cout << ", erased value" << std::flush;

			find(new_value);
			calculateTimeResult(find_TR, getLastTime(), r);
			std::cout << ", found value" << std::flush;

			sort();
			calculateTimeResult(sort_TR, getLastTime(), r);
			std::cout << ", sorted" << std::flush;

			clear();
			calculateTimeResult(clear_TR, getLastTime(), r);
			std::cout << ", cleared" << std::endl;
		}

		std::cout.setf(std::ios::fixed);
		std::cout.precision(6);

		std::cout <<
		"\n\n----------Analyze results----------\n"

		"Repeats: " << repeats << " | "
		"N: " << data_size <<

		"\nGenerate:\n"
		"\tMIN: " << gen_TR.min << " s | "
		"MAX: " << gen_TR.max << " s | "
		"Average: " << gen_TR.mean << " s"

		"\nAdd:\n"
		"\tMIN: " << add_TR.min << " s | "
		"MAX: " << add_TR.max << " s | "
		"Average: " << add_TR.mean << " s"

		"\nErase:\n"
		"\tMIN: " << erase_TR.min << " s | "
		"MAX: " << erase_TR.max << " s | "
		"Average: " << erase_TR.mean << " s"

		"\nFind:\n"
		"\tMIN: " << find_TR.min << " s | "
		"MAX: " << find_TR.max << " s | "
		"Average: " << find_TR.mean << " s"

		"\nSort:\n"
		"\tMIN: " << sort_TR.min << " s | "
		"MAX: " << sort_TR.max << " s | "
		"Average: " << sort_TR.mean << " s"

		"\nClear:\n"
		"\tMIN: " << clear_TR.min << " s | "
		"MAX: " << clear_TR.max << " s | "
		"Average: " << clear_TR.mean << " s"

		<< std::endl;
	}

protected:
	void timerStart()
	{
		clock_time = clock();
	}

	double timerStop()
	{
		clock_time = clock() - clock_time;
		last_time = static_cast<double>(clock_time) / CLOCKS_PER_SEC;
		return last_time;
	}
private:
	struct TimeResults
	{
		TimeResults() : min(0.0), mean(0.0), max(0.0), sum(0.0) {}

		double min, mean, max, sum;
	};

	void calculateTimeResult(TimeResults& TR, double time, size_t iteration)
	{
		if (time < TR.min || iteration == 0) { TR.min = time; }
		if (time > TR.max || iteration == 0) { TR.max = time; }

		TR.sum += time;
		TR.mean = TR.sum / (iteration + 1);
	}

	double getLastTime()
	{
		return last_time;
	}

	double last_time;
	clock_t clock_time;
};

#endif /* ANALYZER_H  */

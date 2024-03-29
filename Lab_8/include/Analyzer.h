#ifndef ANALYZER_H
#define ANALYZER_H

#include "pch.h"

extern bool SHOW_TRACE;

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
			if (SHOW_TRACE)
			{
				std::cout << "\n" << "Iteration " << r << std::flush;
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

			else
			{
				generate(data_size);
				calculateTimeResult(gen_TR, getLastTime(), r);

				T new_value = rand();
				add(new_value);
				calculateTimeResult(add_TR, getLastTime(), r);

				erase(0);
				calculateTimeResult(erase_TR, getLastTime(), r);

				find(new_value);
				calculateTimeResult(find_TR, getLastTime(), r);

				sort();
				calculateTimeResult(sort_TR, getLastTime(), r);

				clear();
				calculateTimeResult(clear_TR, getLastTime(), r);
			}
		}

		std::cout.setf(std::ios::fixed);
		std::cout.precision(6);
		std::cout << "\n\n"
		"+--------------------Analyze results--------------------+" "\n"

		"| " "Repeats: " << std::left << std::setw(16) << repeats << " | "
		"N: " << std::left << std::setw(23) << data_size << "|\n"
		"+-------------+-------------+-------------+-------------+" "\n"
		"| Operation   | Minimum, s  | Maximum, s  | Average, s  |" "\n"
		"+-------------+-------------+-------------+-------------+" "\n"

		"| Generate    | " << 
		std::left << std::setw(12) << gen_TR.min << "| " <<
		std::left << std::setw(12) << gen_TR.max << "| " <<
		std::left << std::setw(12) << gen_TR.mean << "|\n"

		"| Add         | " <<
		std::left << std::setw(12) << add_TR.min << "| " <<
		std::left << std::setw(12) << add_TR.max << "| " <<
		std::left << std::setw(12) << add_TR.mean << "|\n" <<

		"| Erase       | " <<
		std::left << std::setw(12) << erase_TR.min << "| " <<
		std::left << std::setw(12) << erase_TR.max << "| " <<
		std::left << std::setw(12) << erase_TR.mean << "|\n"

		"| Find        | " <<
		std::left << std::setw(12) << find_TR.min << "| " <<
		std::left << std::setw(12) << find_TR.max << "| " <<
		std::left << std::setw(12) << find_TR.mean << "|\n"

		"| Sort        | " <<
		std::left << std::setw(12) << sort_TR.min << "| " <<
		std::left << std::setw(12) << sort_TR.max << "| " <<
		std::left << std::setw(12) << sort_TR.mean << "|\n"

		"| Clear       | " <<
		std::left << std::setw(12) << clear_TR.min << "| " <<
		std::left << std::setw(12) << clear_TR.max << "| " <<
		std::left << std::setw(12) << clear_TR.mean << "|\n"
		"+-------------+-------------+-------------+-------------+" "\n"

		<< std::endl;
	}

protected:
	void timerStart()
	{
		clockTime = clock();
	}

	double timerStop()
	{
		clockTime = clock() - clockTime;
		lastTime = static_cast<double>(clockTime) / CLOCKS_PER_SEC;
		return lastTime;
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
		return lastTime;
	}

	double lastTime;
	clock_t clockTime;
};

#endif /* ANALYZER_H */

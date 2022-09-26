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
	virtual void run(size_t repeats, size_t data_size) = 0;

	double getLastTime()
	{
		return last_time;
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

private:
	double last_time;
	clock_t clock_time;
};

#endif /* ANALYZER_H  */

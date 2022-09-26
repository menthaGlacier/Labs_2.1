#ifndef QUEUE_ANALYZER
#define QUEUE_ANALYZER

#include "Analyzer.h"
#include "pch.h"
#include <queue>

template<class T>
class QueueAnalyzer : public Analyzer<T>
{
public:
	using Analyzer<T>::getLastTime;
	using Analyzer<T>::timerStart;
	using Analyzer<T>::timerStop;
	using Analyzer<T>::calculateTimeResult;

	typedef typename Analyzer<T>::TimeResults TimeResults;

	void generate(size_t amount) override
	{
		clear();
		timerStart();
		for (size_t i = 0; i < amount; i++)
		{
			data.push(rand());
		}
		timerStop();
	}

	void add(const T& element) override
	{
		timerStart();
		data.push(element);
		timerStop();
	}

	void clear() override
	{
		timerStart();
		while(!data.empty()) 
		{
			data.pop();
		}
		timerStop();
	}

	void erase(size_t index) override
	{
		timerStart();
		size_t size = data.size();
		if (index >= size) 
		{
			timerStop();
		   	return; 
		}

		for (size_t i = 0; i < size; i++)
		{
			if (i != index) { data.push(data.front()); }
			data.pop();
		}
		timerStop();
	}

	int find(const T& value) override
	{
		timerStart();
		if (data.empty()) 
		{
			timerStop();
		   	return -1;
		}
		std::queue<T> copy(data);

		size_t size = copy.size();

		for (size_t i = 0; i < size; i++)
		{
			if (copy.front() == value) 
			{
				timerStop();
			   	return i;
		   	}
			copy.pop();
		}

		timerStop();
		return -1;
	}
	
	void sort() override
	{
		timerStart();
		size_t size = data.size();

		if (size < 2) 
		{
			timerStop();
		   	return;
	   	}

		T* data_array = new T[size];

		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j <= i; j++)
			{
				if (j == i)
				{
					data_array[j] = data.front();
					break;
				}

				if (data.front() <= data_array[j])
				{
					for (size_t k = 0; j+k != i; k++)
					{
						data_array[i-k] = data_array[i-k-1];
					}
					data_array[j] = data.front();
					break;
				}
			}
			
			data.pop();
		}

		for (size_t i = 0; i < size; i++)
		{
			data.push(data_array[i]);
		}

		delete[] data_array;
		timerStop();
	}

	void printData() override
	{
		std::queue<T> copy(data);
		for (size_t i = 0; !copy.empty(); i++)
		{
			std::cout << "<-" << copy.front();
			copy.pop();
		}
	}

	void run(size_t repeats, size_t data_size) override
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
public:
	std::queue<T> data;
};

#endif /* QUEUE_ANALYZER */

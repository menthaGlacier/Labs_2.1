#ifndef QUEUE_ANALYZER
#define QUEUE_ANALYZER

#include "Analyzer.h"
#include "pch.h"
#include <queue>

template<class T>
class QueueAnalyzer : public Analyzer<T>
{
public:
	using Analyzer<T>::timerStart;
	using Analyzer<T>::timerStop;

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
		if (index < size) 
		{
			for (size_t i = 0; i < size; i++)
			{
				if (i != index) { data.push(data.front()); }
				data.pop();
			}
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
public:
	std::queue<T> data;
};

#endif /* QUEUE_ANALYZER */

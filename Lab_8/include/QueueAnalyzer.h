#ifndef QUEUE_ANALYZER
#define QUEUE_ANALYZER

#include "Analyzer.h"
#include "pch.h"
#include <queue>

template<class T>
class QueueAnalyzer : public Analyzer<T>
{
public:
	void generate(size_t amount) override
	{
		clear();
		
		for (size_t i = 0; i < amount; i++)
		{
			data.push(rand());
		}
	}

	void add(const T& element) override
	{
		data.push(element);
	}

	void clear() override
	{
		while(!data.empty()) 
		{
			data.pop();
		}
	}

	void erase(size_t index) override
	{
		size_t size = data.size();
		if (index >= size) { return; }

		for (size_t i = 0; i < size; i++)
		{
			if (i != index) { data.push(data.front()); }
			data.pop();
		}
	}

	int find(const T& value) override
	{
		if (data.empty()) { return -1;}
		std::queue<T> copy(data);

		size_t size = copy.size();

		for (size_t i = 0; i < size; i++)
		{
			if (copy.front() == value) { return i; }
			copy.pop();
		}

		return -1;
	}
	
	void sort() override
	{
		size_t size = data.size();

		if (size < 2) { return; }

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

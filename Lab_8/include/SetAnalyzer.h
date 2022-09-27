#ifndef SET_ANALYZER
#define SET_ANALYZER

#include "Analyzer.h"
#include "pch.h"
#include <set>

template <class T>
class SetAnalyzer : public Analyzer<T>
{
public:
    using Analyzer<T>::timerStart;
    using Analyzer<T>::timerStop;
	typedef typename std::set<T>::iterator set_iterator;

	void generate(size_t amount) override
	{
		clear();
		timerStart();
		for (size_t i = 0; i < amount; i++)
		{
			data.insert(rand());
		}
		timerStop();
	}

	void add(const T& element) override
	{
		timerStart();
		data.insert(element);
		timerStop();
	}

	void clear() override
	{
		timerStart();
		data.clear();	
		timerStop();
	}

	void erase(size_t index) override
	{
		timerStart();
		size_t size = data.size();
		if (index < size) 
		{
			data.erase(std::next(data.begin(), index));
		}

		timerStop();
	}

	int find(const T& value) override
	{
		timerStart();
		set_iterator found_iter = data.find(value);
		
		int return_value = 0;

		for (set_iterator iter = data.begin(); iter != data.end(); iter++)
		{
			if (iter == found_iter)
		   	{
				timerStop();
			   	return return_value;
			}
			return_value++;
		}
		timerStop();
		return -1;
	}
	
	void sort() override
	{
		timerStart();
		timerStop();
	}

	void printData() override
	{
		std::cout << "{";

		for (const T& i : data)
		{
			std::cout << " " << i;
		}
		std::cout << " }" << std::flush;
	}

public:
	std::set<T> data;
};
#endif /* SET_ANALYZER */

#ifndef ANALYZER_H
#define ANALYZER_H

template<class T>
class Analyzer
{
public:	
	virtual void generate(size_t amount) = 0;
	virtual void add(const T& element) = 0;
	virtual	void clear() = 0;
	virtual void erase(size_t index) = 0;
	virtual int find(const T& value) = 0;
	virtual void sort() = 0;
	virtual void printData() = 0;
	virtual void run(size_t repeats, size_t data_size) = 0;

	uint64_t getLastTime()
	{
		return last_time;
	}

private:
	uint64_t last_time;
};

#endif /* ANALYZER_H  */

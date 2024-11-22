#pragma once

#include <chrono>
#include <iostream>

namespace ZZG
{

class Timer
{
public:
	//构造函数保存开始时间
	Timer() :
		time_(std::clock())
	{

	}

	//经过了多少时间
	double elapsed() const
	{
		return (double)(std::clock() - time_) / double(CLOCKS_PER_SEC);
	}

	//重新设置开始时间
	void restart()
	{
		time_ = std::clock();
	}

	//计时范围 min-max
	double min() const
	{
		return (double) 1 / double(CLOCKS_PER_SEC);
	}

	double max() const 
	{
		return (double((std::numeric_limits<std::clock_t>::max)())
			- double(time_)) / double(CLOCKS_PER_SEC);
	}

	~Timer() = default;

private:
	clock_t time_;
};



class AutoTimer : Timer
{
public:
	//将信息进行输出
	explicit AutoTimer(std::ostream& os)
		:os_(os)
	{

	}

	~AutoTimer()
	{
		os_ << "spend time is " << elapsed()<<'\n';
	}
private:
	std::ostream& os_;
};


}













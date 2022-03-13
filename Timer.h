#pragma once
#include <chrono>
#include <thread>
#include <ostream>

using Myclock=std::chrono::system_clock;

class ReloadTimer
{
public:
	ReloadTimer(Myclock::time_point SysClock)  
	{
		StartedClock = SysClock;
	};
	bool CheckTimeToReload();
	bool CkeckTimeToShutDown();
	
	Myclock::time_point GetStarted()
	{
		return StartedClock;
	}

private:
	Myclock::time_point StartedClock;
	
};
#pragma warning(disable : 4996)
#include <iostream>
#include "Timer.h"
#include <ctime>
#include <iomanip>

void StartProgramm()
{
	system("D:/Wicked_Ways_2/Binaries/Win64/WindowsServer/Wicked_Ways_2Server.exe -log");
}

void StopProgramm()
{
	int i = system("taskkill/IM Wicked_Ways_2Server.exe /F");
	if (i == 0)
		std::cout << "killingprocess" << std::endl;
	else
	{
		std::cout << "don't kill process" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "startProgramm" << std::endl;
		StartProgramm();
	}
		
}
bool CheckIsInProgress()
{
	system("tasklist");
	return true;
}
int main()
{

	//CheckIsInProgress();
	//StopProgramm();
	//auto nowtime = std::chrono::system_clock::now();
	std::cout << "wait" << std::endl;
	while (true)
	{
		std::time_t const end_time = std::time(NULL);
		auto m = std::localtime(&end_time);
		if (m->tm_hour == 15 && m->tm_min == 41)
		{
			std::cout << "checked time" << std::endl;
			StopProgramm();
		}
		
	}
	
	
	//std::cout << std::put_time(std::localtime(&end_time), "%F %T") << std::endl;
	//ReloadTimer* starttimer = new ReloadTimer(std::chrono::system_clock::now());
	//std::thread SecondThread(StartProgramm);
	//
	//std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	//StopProgramm();
	//
	//SecondThread.detach();
	//
	////std::cout << "current date and time: "<< std::ctime(&(std::chrono::system_clock::now())) << std::endl;
	//delete starttimer;
	return 0;
}
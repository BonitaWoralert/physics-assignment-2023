#pragma once
#include <chrono>

class Timer
{
public: 
	Timer(); //constructor

	float GetDeltaTime(); //time since last frame
	void Tick(); //store time of last frame;
private:
	std::chrono::steady_clock::time_point lastFrame; 
};


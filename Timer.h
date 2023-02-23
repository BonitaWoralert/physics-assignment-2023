#pragma once
#include <chrono>;

using namespace std::chrono;

class Timer
{
public:
	Timer(); //constructor

	float GetDeltaTime(); //request time since last frame
	void Tick(); //store time of last frame

private:
	steady_clock::time_point lastFrame; //std::chrono::steady_clock
};


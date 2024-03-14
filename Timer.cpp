#include "Timer.h"

Timer::Timer()
{
	lastFrame = std::chrono::steady_clock::now();
}

float Timer::GetDeltaTime()
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - lastFrame).count();
}

void Timer::Tick()
{
	lastFrame = std::chrono::steady_clock::now();
}

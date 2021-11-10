#pragma once

class Clock
{
public:
	Clock();
	void run();

private:
	void tick();
	void show();
	int _Second;
	int _Minute;
	int _Hour;
};
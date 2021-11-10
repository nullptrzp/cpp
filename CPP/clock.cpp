#define _CRT_SECURE_NO_WARNINGS
#include"clock.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<iomanip>
using namespace std;

Clock::Clock()
{
	time_t t = time(NULL);
	tm local = *localtime(&t);
	_Hour = local.tm_hour;
	_Minute = local.tm_min;
	_Second = local.tm_sec;
}

void Clock::tick()
{
	Sleep(1000);
	while (++_Second==60) {
		_Second = 0;
		if (++_Minute == 60) {
			_Minute = 0;
			if (++_Hour == 24) {
				_Hour = 0;
			}
		}
	}
}

void Clock::show()
{
	system("cls");
	cout << setw(2) << setfill('0') << _Hour << " : "
		<< setw(2) << setfill('0') << _Minute << " : "
		<< setw(2) << setfill('0') << _Second << endl;
}

void Clock::run()
{
	while (true) {
		tick();
		show();
	}
}
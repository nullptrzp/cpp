#include"Apple.h"
#include<iostream>
using namespace std;

void Apple::take(int num) const
{
	cout << "take func " << num << endl;
}
void Apple::add(int num)
{
	cout << "普通成员函数调用常成员变量"<<apple_Number << endl;
	var = var + 1;
	take(num);
}
void Apple::add(int num) const
{
	cout << "常成员函数调用普通变量 " << endl;
	//var = var + 2;	//erroe
	take(num);
}
int Apple::getCount() const
{
	add(5);
	take(1);
	return apple_Number;
}
#include"Apple.h"
#include<iostream>
using namespace std;

void Apple::take(int num) const
{
	cout << "take func " << num << endl;
}
void Apple::add(int num)
{
	cout << "��ͨ��Ա�������ó���Ա����"<<apple_Number << endl;
	var = var + 1;
	take(num);
}
void Apple::add(int num) const
{
	cout << "����Ա����������ͨ���� " << endl;
	//var = var + 2;	//erroe
	take(num);
}
int Apple::getCount() const
{
	add(5);
	take(1);
	return apple_Number;
}
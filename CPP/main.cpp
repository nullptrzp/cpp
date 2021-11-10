#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>
#include<cassert>
#include<cstdlib>
#include"Apple.h"
#include"clock.h"
using namespace std;

//Apple class
void test01()
{
	Apple a;
	cout << a.getCount();
	/*cout << a.getCount() << endl;
	a.add(10);
	const Apple b(3);
	b.add(100);*/
}

//clock class
void test02()
{
	Clock c;
	c.run();
}

//operator classname()	类的转化
namespace a {
	class twoOperand;
	class oneOperand
	{
	public:
		oneOperand(int i) :_a(i) {};
		operator twoOperand();
		void show() { cout << _a << endl; }
	private:
		int _a;
	};

	class twoOperand
	{
	public:
		twoOperand(int i, int j) :_a(i), _b(j) {};
		operator oneOperand();
		void show() { cout << _a << " " << _b << endl; }
	private:
		int _a;
		int _b;
	};

	twoOperand::operator oneOperand() { return oneOperand(_a); }
	oneOperand::operator twoOperand() { return twoOperand(_a, 0); }

	void test03()
	{
		oneOperand one(1);
		one.show();
		twoOperand two(2, 3);
		two.show();
		twoOperand t = one;
		t.show();
		oneOperand o = two;
		o.show();
	}
}

//全局重载new、delete

int main(int argc, char* argv[])
{
	int array[5] = { 1,2,3,4,5 };
	//int (&rr) [5] = r;		//数组引用
	//int* p = (int*)((int)r + 1);
	//test01();
	//test02();
	//a::test03();

	return EXIT_SUCCESS;
}
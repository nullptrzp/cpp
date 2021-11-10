#define _CRT_NO_SECURE_WARNINGS
#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

class A {
public:
	A(int i) :_num(i) {};
	~A() { cout << "析构函数调用"; };
private:
	int _num;
};

void* ::operator new(size_t t) {
	cout << "new重载";
	return malloc(t);
}

void* ::operator new[](size_t t) {
	cout << "new[]重载";
	return malloc(t);
}

void ::operator delete(void* p) {
	cout << "delete重载";
	free(p);
}

void ::operator delete[](void* p) {
	cout << "delete[]重载";
	free(p);
}

int main() {
	int* i = new int;
	delete i;
	int* ia = new int[3];
	delete[] ia;
	A* a = new A(1);
	delete a;
	A* aa = new A[2]{ 2,3 };
	delete[] aa;

	return EXIT_SUCCESS;
}
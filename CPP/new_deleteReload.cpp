#define _CRT_NO_SECURE_WARNINGS
#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

class A {
public:
	A(int i) :_num(i) {};
	~A() { cout << "������������"; };
private:
	int _num;
};

void* ::operator new(size_t t) {
	cout << "new����";
	return malloc(t);
}

void* ::operator new[](size_t t) {
	cout << "new[]����";
	return malloc(t);
}

void ::operator delete(void* p) {
	cout << "delete����";
	free(p);
}

void ::operator delete[](void* p) {
	cout << "delete[]����";
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
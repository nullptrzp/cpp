#include<iostream>
#include<string>
using namespace std;

struct Person {
	int age;
	const char name[10];
};

void Print(void* arr, int len, int elemSize, void(*selfPrint)(void*))
{
	char* addr = (char*)arr;
	for (int i = 0; i < len; i++) {
		char* arraddr = addr + elemSize * i;
		selfPrint(arraddr);
	}
}

int Find(void* arr, int len, int elemSize, void* data, int(*selfJudge)(void* item1, void* item2))
{
	char* addr = (char*)arr;
	for (int i = 0; i < len; i++) {
		char* elemAddr = addr + i * elemSize;
		if (selfJudge(data, elemAddr)) {
			return i;
		}
	}
	return -1;
}

void myPrint(void* data)
{
	Person* p = (Person*)data;
	cout << p->name << ": " << p->age << endl;
}

int myJudge(void* data, void* item)
{
	Person* p1 = (Person*)data;
	Person* p2 = (Person*)item;
	if (p1->age == p2->age && strcmp(p1->name, p2->name) == 0) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	Person p[3] = {
		{11,"qw"},
		{12,"we"},
		{13,"er"}
	};
	//Print(&p, sizeof(p)/sizeof(p[0]),sizeof(p[0]),myPrint);
	Person p1 = { 12,"we"};
	cout << Find(&p, 5, sizeof(p[0]), &p1, myJudge);

	return EXIT_SUCCESS;
}
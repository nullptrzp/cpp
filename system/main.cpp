#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;

namespace myShutDown {
	void print();

	void myshutDown() {
		system("title c++�ػ�����");
		system("mode con cols=48 lines=23");
		system("color 0B");
		system("date /T");
		system("TIME /T");
		char cmd[20] = "shutdown -t -s";
		char t[5] = "0";
		print();
		int c = 0;
		cin >> c;
		switch (c){
		case 1: {
			cout << "�����ڶ�������Զ��ػ���" << endl;
			cin >> t;
			system(strcat(cmd, t));
			break;
		}
		case 2:
			system("shutdown -p"); break;
		case 3:
			system("shutdown -l"); break;
		case 0:
			break;
		default:
			perror("error!");
			break;
		} 
	}
	void print() {
		cout << "=|==|==|==|========|==|==|==|=" << endl;
		cout << "C++�ػ�����" << endl;
		cout << "1 10�����ڶ�ʱ�ػ�" << endl << "2 �����ػ�" << endl <<
			"3 ע�������" << "0 �˳�ϵͳ" << endl;
		cout << "==============================" << endl;
	}
}

//void deleteFile();

int main()
{
	myShutDown::myshutDown();

	return EXIT_SUCCESS;
}
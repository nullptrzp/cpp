#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<math.h>
using namespace std;

class Snake;

//游戏主控
void startGame();
//欢迎界面
void welcomeGame();
//打印地图
void creatMap();
//控制鼠标
void gotoXY(short x, short y);
//构造蛇
Snake* initSnake();
//构造食物点
Snake* createFood();
//运行游戏
void runGame(Snake* head);
//蛇移动
Snake* moveSnake(Snake* head, int direction);


int main()
{
	startGame();

	return EXIT_SUCCESS;
}

void startGame()
{
	system("mode con cols=100 lines=35");
	system("color 0B");
	system("title 贪吃蛇小游戏");
	welcomeGame();
	creatMap();
	Snake* shead = initSnake();
	runGame(shead);
}

void welcomeGame()
{
	cout << "\n\n\n\n\n\n\n" <<
		"\t\t\t\t==============================\t\t\t\t" <<
		"\n\n\n" <<
		"\t\t\t\t\t欢迎进入游戏\t\t\t\t\t" <<
		"\n\n\n" <<
		"\t\t\t\t==============================\t\t\t\t" << endl;
	system("pause");
	system("cls");
}

void creatMap()
{
	for (short i = 0; i < 60; i+=2) {
		gotoXY(i, 0);
		cout << "■" ;
		gotoXY(i, 29);
		cout << "■";
	}
	for (int j = 0; j < 30; j++) {
		gotoXY(0, j);
		cout << "■";
		gotoXY(58, j);
		cout << "■";
	}
}

void gotoXY(short x, short y)
{
	COORD pos = { x,y };
	HANDLE hio = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hio, pos);
}

class Snake 
{
public:
	short _x;
	short _y;
	Snake* next;
public:
	Snake():_x(28),_y(14),next(0){}
	Snake(int x, int y):_x(x),_y(y),next(0){}
	void showNode() {
		COORD pos = { this->_x,this->_y };
		HANDLE hio = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hio, pos);
		cout << "■";
	}
	void clearNode() {
		COORD pos = { this->_x,this->_y };
		HANDLE hio = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hio, pos);
		cout << "  ";
	}
};

Snake* initSnake()
{
	srand((unsigned int)time(0));
	int xtmp = 0, ytmp = 0;
	xtmp = rand() % 53, ytmp = rand() % 29;
	int x = xtmp < 2 ? xtmp + 2 : xtmp;
	int y = ytmp < 1 ? ytmp + 1 : ytmp;
	Snake* head = new Snake(x, y);
	head->showNode();
	Snake* middle = new Snake(x + 2, y);
	head->next = middle;
	middle->showNode();
	Snake* tail = new Snake(x + 4, y);
	middle->next = tail;
	tail->showNode();
	return head;
}

Snake* createFood()
{
	srand((unsigned int)time(NULL));
	short x = rand() % 57;
	short y = rand() % 29;
	x = x < 2 ? x + 2 : x;
	x = x % 2 == 0 ? x : x - 1;
	y = y < 1 ? y + 1 : y;
	Snake* food = new Snake(x, y);
	food->showNode();
	return food;
}

void runGame(Snake* head)
{
	Snake* Shead = head;
	Snake* food = nullptr;
	int ch = 0;
	food = createFood();
	while (true) {
		if (_kbhit()) {
			if ((ch = _getch()) != 0x1B && ch != 0x0D) {
				switch (ch) {
				case 72: {
					Shead = moveSnake(Shead, 72);
					break;
				}
				case 80: {
					Shead = moveSnake(Shead, 80);
					break;
				}
				case 75: {
					Shead = moveSnake(Shead, 75);
					break;
				}
				case 77: {
					Shead = moveSnake(Shead, 77);
					break;
				}
				default:
					break;
				}
			}
			else
				break;
		}
		else
			Shead = moveSnake(Shead, ch);
		Sleep(300);
		if (abs(food->_x-Shead->_x)<2&&abs(food->_y-Shead->_y)<1) {
			food->next = Shead;
			Shead = food;
			food = createFood();
		}
		else
			continue;
	}
}

Snake* moveSnake(Snake* head, int direction)
{
	Snake* newHead = head;
	Snake* p = nullptr;
	Snake* node = new Snake;
	node->next = newHead;
	switch (direction){
	case 75: {
		node->_x = newHead->_x - 2;
		if (node->_x < 1) {
			system("cls");
			cout<<"游戏结束！";
			return nullptr;
		}
		node->_y = newHead->_y;
		break;
	}
	case 77: {
		node->_x = newHead->_x + 2;
		if (node->_x > 58) {
			system("cls");
			cout<<"游戏结束！";
			return nullptr;
		}
		node->_y = newHead->_y;
		break;
	}
	case 72: {
		node->_x = newHead->_x;
		node->_y = newHead->_y - 1;
		if (node->_y < 1) {
			system("cls");
			cout<<"游戏结束！";
			return nullptr;
		}
		break;
	}
	case 80: {
		node->_x = newHead->_x;
		node->_y = newHead->_y + 1;
		if (node->_y > 28) {
			system("cls");
			cout<<"游戏结束！";
			return nullptr;
		}
		break;
	}
	default:
		break;
	}
	newHead = node;
	p = newHead;
	while (p->next->next != nullptr) {
		p = p->next;
	}
	p->next->clearNode();
	delete(p->next);
	p->next = nullptr;
	p = newHead;
	while (p->next != nullptr) {
		p->showNode();
		p = p->next;
	}
	return newHead;
}
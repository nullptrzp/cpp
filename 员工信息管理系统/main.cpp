#include"employee.h"
#include"manager.h"
#include"saleMan.h"
#include"saleManager.h"
#include"technician.h"
#include"company.h"
#include"global.h"
#include<fstream>
#include<string>

void showMenu()
{
	cout << "******************************" << endl;
	cout << "***  企业员工信息管理系统  ***" << endl;
	cout << "***     1 添加员工信息     ***" << endl;
	cout << "***     2 查看员工信息     ***" << endl;
	cout << "***     3 查看财务信息     ***" << endl;
	cout << "***     4 清空员工信息     ***" << endl;
	cout << "***     0   退出系统       ***" << endl;
	cout << "******************************" << endl;
}

//添加员工信息
void addWorker()
{
	cout << "************添加员工信息********" << endl;
	cout << "***     1   添加经理信息     ***" << endl;
	cout << "***     2 添加销售经理信息   ***" << endl;
	cout << "***     3 添加销售人员信息   ***" << endl;
	cout << "***     4 添加技术人员信息   ***" << endl;
	cout << "***     0   返回上级菜单     ***" << endl;
	cout << "*******************************" << endl;
	cout << "请输入您想要添加员工的类型：";
	string name="";
	int saleMoney = 0;
	int workTime = 0;
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		cout << "请输入姓名：";
		cin >> name;
		manager* m = new manager(name);
		ofstream ofs(managerFile, ios::out | ios::app);
		ofs << m->getName() << " " << m->get_ID() << " " << m->getLevel() << endl;
		ofs.close();
		delete m;
		cout << "信息添加成功！" << endl;
		cin.get();
		cin.get();
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		cout << "请输入姓名：";
		cin >> name;
		saleManager* sManager = new saleManager(name);
		ofstream ofs(saleManagerFile, ios::out | ios::app);
		ofs << sManager->getName() << " " << sManager->get_ID() << " " << sManager->getLevel() << endl;
		ofs.close();
		delete sManager;
		cout << "信息添加成功！" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入本月销售额：";
		cin >> saleMoney;
		saleMan* sMan = new saleMan(name,saleMoney);
		ofstream ofs(saleManFile, ios::out | ios::app);
		ofs << sMan->getName() << " " << sMan->get_ID() << " " << sMan->getLevel() << endl;
		ofs.close();
		cout << "信息添加成功！" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入本月工作时长：";
		cin >> workTime;
		technician* t = new technician(name,workTime);
		ofstream ofs(technicianFile, ios::out | ios::app);
		ofs << t->getName() << " " << t->get_ID() << " " << t->getLevel() << endl;
		ofs.close();
		delete t;
		cout << "信息添加成功！" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 0:
		system("cls");
		return;
	default:
		break;
	}
}

//查看员工信息
void getInfo()
{
	cout << "************查看员工信息********" << endl;
	cout << "***     1   查看经理信息     ***" << endl;
	cout << "***     2 查看销售经理信息   ***" << endl;
	cout << "***     3 查看销售人员信息   ***" << endl;
	cout << "***     4 查看技术人员信息   ***" << endl;
	cout << "***     0   返回上级菜单     ***" << endl;
	cout << "*******************************" << endl;
	cout << "请输入您想要查看员工的类型：";
	string name = "";
	string id = "";
	int level = 0;
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		cout << "*******经理信息如下*******" << endl << endl;;
		ifstream ifs(managerFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "姓名：" << name << " ID：" << id << " 级别：" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		cout << "*******销售经理信息如下*******" << endl << endl;;
		ifstream ifs(saleManagerFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "姓名：" << name << " ID：" << id << " 级别：" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		cout << "*******销售人员信息如下*******" << endl << endl;;
		ifstream ifs(saleManFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "姓名：" << name << " ID：" << id << " 级别：" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		cout << "*******技术人员信息如下*******" << endl << endl;;
		ifstream ifs(technicianFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "姓名：" << name << " ID：" << id << " 级别：" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	default:
		break;
	}
}

//查看财务信息
void getFinancialInfo()
{
	cout << "***********************************" << endl;
	cout << "*****   公司财务状态如下所示   ****" << endl;
	cout << "***********************************" << endl << endl;
	//Company c;
	cout << "当前公司人数：" << Company::number - 999 << endl;
	cout << "本月销售总额：" << Company::totalSalemoney << endl;
	cout << "本月工资总额：" << Company::totalSalary << endl;
	system("pause");
	system("cls");
}

//清空员工信息
void clearInfo()
{
	cout << "************清空员工信息********" << endl;
	cout << "***     1   清空经理信息     ***" << endl;
	cout << "***     2 清空销售经理信息   ***" << endl;
	cout << "***     3 清空销售人员信息   ***" << endl;
	cout << "***     4 清空技术人员信息   ***" << endl;
	cout << "***     5 清空所有人员信息   ***" << endl;
	cout << "***     0   返回上级菜单     ***" << endl;
	cout << "*******************************" << endl;
	cout << "请输入您想要清空的类型：";
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		ofstream ofs(managerFile, ios::trunc);
		ofs.close();
		cout << "信息清空完毕。" << endl;
		system("pause");
		system("cls");
		break;
	}
	default:
		break;
	}
}

int main(int argc, char* argv[])
{
	while (true) {
		showMenu();
		int select = 0;
		cout << "请输入您想要进行的操作【0-4】：";
		cin >> select;
		switch (select){
		case 1:		//添加员工信息
			system("cls");
			addWorker();
			break;
		case 2:		//查看员工信息
			system("cls");
			getInfo();
			break;
		case 3:		//查看财务信息
			system("cls");
			getFinancialInfo();
			break;
		case 4:		//清空员工信息
			system("cls");
			clearInfo();
			break;
		case 0:		//退出系统
			system("cls");
			return EXIT_SUCCESS;
		default:
			break;
		}
	}
	return EXIT_SUCCESS;
}
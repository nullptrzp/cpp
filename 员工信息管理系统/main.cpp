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
	cout << "***  ��ҵԱ����Ϣ����ϵͳ  ***" << endl;
	cout << "***     1 ���Ա����Ϣ     ***" << endl;
	cout << "***     2 �鿴Ա����Ϣ     ***" << endl;
	cout << "***     3 �鿴������Ϣ     ***" << endl;
	cout << "***     4 ���Ա����Ϣ     ***" << endl;
	cout << "***     0   �˳�ϵͳ       ***" << endl;
	cout << "******************************" << endl;
}

//���Ա����Ϣ
void addWorker()
{
	cout << "************���Ա����Ϣ********" << endl;
	cout << "***     1   ��Ӿ�����Ϣ     ***" << endl;
	cout << "***     2 ������۾�����Ϣ   ***" << endl;
	cout << "***     3 ���������Ա��Ϣ   ***" << endl;
	cout << "***     4 ��Ӽ�����Ա��Ϣ   ***" << endl;
	cout << "***     0   �����ϼ��˵�     ***" << endl;
	cout << "*******************************" << endl;
	cout << "����������Ҫ���Ա�������ͣ�";
	string name="";
	int saleMoney = 0;
	int workTime = 0;
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		cout << "������������";
		cin >> name;
		manager* m = new manager(name);
		ofstream ofs(managerFile, ios::out | ios::app);
		ofs << m->getName() << " " << m->get_ID() << " " << m->getLevel() << endl;
		ofs.close();
		delete m;
		cout << "��Ϣ��ӳɹ���" << endl;
		cin.get();
		cin.get();
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		cout << "������������";
		cin >> name;
		saleManager* sManager = new saleManager(name);
		ofstream ofs(saleManagerFile, ios::out | ios::app);
		ofs << sManager->getName() << " " << sManager->get_ID() << " " << sManager->getLevel() << endl;
		ofs.close();
		delete sManager;
		cout << "��Ϣ��ӳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		cout << "������������";
		cin >> name;
		cout << "�����뱾�����۶";
		cin >> saleMoney;
		saleMan* sMan = new saleMan(name,saleMoney);
		ofstream ofs(saleManFile, ios::out | ios::app);
		ofs << sMan->getName() << " " << sMan->get_ID() << " " << sMan->getLevel() << endl;
		ofs.close();
		cout << "��Ϣ��ӳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		cout << "������������";
		cin >> name;
		cout << "�����뱾�¹���ʱ����";
		cin >> workTime;
		technician* t = new technician(name,workTime);
		ofstream ofs(technicianFile, ios::out | ios::app);
		ofs << t->getName() << " " << t->get_ID() << " " << t->getLevel() << endl;
		ofs.close();
		delete t;
		cout << "��Ϣ��ӳɹ���" << endl;
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

//�鿴Ա����Ϣ
void getInfo()
{
	cout << "************�鿴Ա����Ϣ********" << endl;
	cout << "***     1   �鿴������Ϣ     ***" << endl;
	cout << "***     2 �鿴���۾�����Ϣ   ***" << endl;
	cout << "***     3 �鿴������Ա��Ϣ   ***" << endl;
	cout << "***     4 �鿴������Ա��Ϣ   ***" << endl;
	cout << "***     0   �����ϼ��˵�     ***" << endl;
	cout << "*******************************" << endl;
	cout << "����������Ҫ�鿴Ա�������ͣ�";
	string name = "";
	string id = "";
	int level = 0;
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		cout << "*******������Ϣ����*******" << endl << endl;;
		ifstream ifs(managerFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "������" << name << " ID��" << id << " ����" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		system("cls");
		cout << "*******���۾�����Ϣ����*******" << endl << endl;;
		ifstream ifs(saleManagerFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "������" << name << " ID��" << id << " ����" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		system("cls");
		cout << "*******������Ա��Ϣ����*******" << endl << endl;;
		ifstream ifs(saleManFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "������" << name << " ID��" << id << " ����" << level << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		system("cls");
		cout << "*******������Ա��Ϣ����*******" << endl << endl;;
		ifstream ifs(technicianFile, ios::in);
		while (ifs >> name && ifs >> id && ifs >> level) {
			cout << "������" << name << " ID��" << id << " ����" << level << endl;
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

//�鿴������Ϣ
void getFinancialInfo()
{
	cout << "***********************************" << endl;
	cout << "*****   ��˾����״̬������ʾ   ****" << endl;
	cout << "***********************************" << endl << endl;
	//Company c;
	cout << "��ǰ��˾������" << Company::number - 999 << endl;
	cout << "���������ܶ" << Company::totalSalemoney << endl;
	cout << "���¹����ܶ" << Company::totalSalary << endl;
	system("pause");
	system("cls");
}

//���Ա����Ϣ
void clearInfo()
{
	cout << "************���Ա����Ϣ********" << endl;
	cout << "***     1   ��վ�����Ϣ     ***" << endl;
	cout << "***     2 ������۾�����Ϣ   ***" << endl;
	cout << "***     3 ���������Ա��Ϣ   ***" << endl;
	cout << "***     4 ��ռ�����Ա��Ϣ   ***" << endl;
	cout << "***     5 ���������Ա��Ϣ   ***" << endl;
	cout << "***     0   �����ϼ��˵�     ***" << endl;
	cout << "*******************************" << endl;
	cout << "����������Ҫ��յ����ͣ�";
	int sel = 0;
	cin >> sel;
	switch (sel){
	case 1: {
		system("cls");
		ofstream ofs(managerFile, ios::trunc);
		ofs.close();
		cout << "��Ϣ�����ϡ�" << endl;
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
		cout << "����������Ҫ���еĲ�����0-4����";
		cin >> select;
		switch (select){
		case 1:		//���Ա����Ϣ
			system("cls");
			addWorker();
			break;
		case 2:		//�鿴Ա����Ϣ
			system("cls");
			getInfo();
			break;
		case 3:		//�鿴������Ϣ
			system("cls");
			getFinancialInfo();
			break;
		case 4:		//���Ա����Ϣ
			system("cls");
			clearInfo();
			break;
		case 0:		//�˳�ϵͳ
			system("cls");
			return EXIT_SUCCESS;
		default:
			break;
		}
	}
	return EXIT_SUCCESS;
}
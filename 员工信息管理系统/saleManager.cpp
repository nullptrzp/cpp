#include"saleManager.h"

saleManager::saleManager() :employee(), _Salary(0) {};

saleManager::saleManager(string name) :employee(name){
    this->_Salary =(int) (totalSalemoney * 0.05 + 5000);
    totalSalary += this->_Salary;
};

void saleManager::upLevel()
{
    this->_Level = 3;
}

// int saleManager::calcSalary()
// {
//     return this->_Salary;
// }

void saleManager::showInfo()
{
    cout << "���۾���������" << this->_Name << endl
        << "���۾����ţ�" << this->_ID << endl
        << "���۾�����" << this->_Level << endl
        << "���۾���нˮ��" << this->_Salary << endl;
}
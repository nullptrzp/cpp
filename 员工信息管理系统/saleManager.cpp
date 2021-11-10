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
    cout << "销售经理姓名：" << this->_Name << endl
        << "销售经理编号：" << this->_ID << endl
        << "销售经理级别：" << this->_Level << endl
        << "销售经理薪水：" << this->_Salary << endl;
}
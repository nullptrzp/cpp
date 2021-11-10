#include"saleMan.h"

saleMan::saleMan() :employee(), _saleMoney(0),_salary(0) {};

saleMan::saleMan(string name, int money) :employee(name), _saleMoney(money) {
    _salary =(int) (_saleMoney * 0.04);
    totalSalary += this->_salary;
    totalSalemoney += _saleMoney;
};

// int saleMan::calcSalary()
// {
//     this->_salary=0.04*this->_saleMoney;
//     return _saleMoney;
// }

void saleMan::upLevel()
{
    this->_Level = 1;
}

void saleMan::showInfo()
{
    cout << "推销员姓名：" << this->_Name << endl
        << "推销员编号：" << this->_ID << endl
        << "推销员级别：" << this->_Level << endl
        << "推销员薪水：" << this->_salary << endl;
}
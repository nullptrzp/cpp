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
    cout << "����Ա������" << this->_Name << endl
        << "����Ա��ţ�" << this->_ID << endl
        << "����Ա����" << this->_Level << endl
        << "����Աнˮ��" << this->_salary << endl;
}
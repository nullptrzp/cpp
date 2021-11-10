#include"manager.h"

manager::manager() :employee(), _Salary(8000) {};

manager::manager(string name) :employee(name), _Salary(8000) {
    totalSalary += this->_Salary;
};

// int manager::calcSalary()
// {
//     this->_Salary=8000;
//     return this->_Salary;
// }

void manager::upLevel()
{
    this->_Level = 4;
}

void manager::showInfo()
{
    cout << "经理姓名：" << this->_Name << endl
        << "经理编号：" << this->_ID << endl
        << "经理级别：" << this->_Level << endl
        << "经理薪水：" << this->_Salary << endl;
}
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
    cout << "����������" << this->_Name << endl
        << "�����ţ�" << this->_ID << endl
        << "������" << this->_Level << endl
        << "����нˮ��" << this->_Salary << endl;
}
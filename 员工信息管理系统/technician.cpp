#include"technician.h"

technician::technician() :employee(), _salary(0), _workTime(0) {};

technician::technician(string name, int time) :
            employee(name), _workTime(time) { 
    this->_salary = _workTime * 100;
    totalSalary += this->_salary;
};

void technician::upLevel()
{
    this->_Level = 3;
}

// int technician::clacSalary()
// {
//     return this->_workTime*100;
// }

void technician::showInfo()
{
    cout << "������Ա������" << this->_Name << endl
        << "������Ա��ţ�" << this->_ID << endl
        << "������Ա����" << this->_Level << endl
        << "������Աнˮ��" << this->_salary << endl;
}
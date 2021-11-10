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
    cout << "技术人员姓名：" << this->_Name << endl
        << "技术人员编号：" << this->_ID << endl
        << "技术人员级别：" << this->_Level << endl
        << "技术人员薪水：" << this->_salary << endl;
}
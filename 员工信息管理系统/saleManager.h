#pragma once
#include"employee.h"

class saleManager :public employee,virtual public Company
{
private:
    int _Salary;
public:
    saleManager();
    saleManager(string name);
    void upLevel();
    //int calcSalary();
    void showInfo();
    //~saleManager();
};
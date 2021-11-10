//#pragma once
#ifndef _MANAGER_H
#define _MANAGER_H
#include"employee.h"

class manager :public employee,virtual public Company
{
private:
    int _Salary;
public:
    manager();
    manager(string name);
    void upLevel();
    //int calcSalary();
    void showInfo();
    //~manager();
};
#endif
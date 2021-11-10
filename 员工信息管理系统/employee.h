//#pragma once
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include<iostream>
#include"company.h"
using namespace std;

class employee:virtual public Company
{
protected:
    string _Name;
    string _ID;
    int _Level;
    //int _Salary;
public:
    employee();
    employee(string name);
    // ~employee();
    virtual void showInfo() = 0;;
    virtual void upLevel() = 0;
    string getName();
    string get_ID();
    int getLevel();
    //virtual int calcSalary()=0;
};
#endif
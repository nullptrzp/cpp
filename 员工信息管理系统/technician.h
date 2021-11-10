//#pragma once
#ifndef _TECHNICIAN_H
#define _TECHNICIAN_H
#include"employee.h"

class technician :public employee,virtual public Company
{
private:
    int _salary;
    int _workTime;
public:
    technician();
    technician(string name,int time);
    void upLevel();
    //int clacSalary();
    void showInfo();
    //~technician();
};
#endif
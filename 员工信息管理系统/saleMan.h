//#pragma once
#ifndef _SALEMAN_H
#define _SALEMAN_H
#include"employee.h"

class saleMan :public employee,virtual public Company
{
protected:
    int _saleMoney;
    int _salary;
public:
    saleMan();
    saleMan(string name, int money);
    void upLevel();
    //int calcSalary();
    void showInfo();
    //~saleManager();
};
#endif
#include"employee.h"
#include<string>

employee::employee() :_Name(""), _Level(1) {
	this->_ID = to_string(++number);
};

employee::employee(string name) :_Name(name), _Level(1) {
	this->_ID = to_string(++number);
};

string employee::getName() { return this->_Name; }

string employee::get_ID() { return this->_ID; }

int employee::getLevel() { return this->_Level; }
#include"company.h"
#include<fstream>
using namespace std;

Company::Company() {
	ifstream ifs(companyFile, ios::in);
	while(ifs>>Company::number && ifs>>Company::totalSalary && ifs>>Company::totalSalemoney){}
	ifs.close();
}

Company::~Company() {
	ofstream ofs(companyFile, ios::out);
	ofs << this->number << " " << this->totalSalary << " " << this->totalSalemoney << endl;
	ofs.close();
}

int Company::totalSalary = 0;
int Company::totalSalemoney = 0;
int Company::number= 0;
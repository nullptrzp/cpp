#include<iostream>
#include<limits>
#include<array>
#include<ctime>
#include<cctype>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<string>
#include<any>
#include<limits>
using namespace std;
#pragma pack(16)
#define myoffsetof(TYPE, MEMBER) (size_t)&(((TYPE*)0)->MEMBER) 

//cout << R"((wod \n wee)";

namespace t1
{
	template<typename T, typename... Args>
	bool pair_comparer(T a, T b, Args... args) {
		return a == b && pair_comparer(args...);
	}
}

int main() 
{
	vector<int> v{ 1,2,3,3,3,3,4,5,6 };
	pair<vector<int>::iterator,vector<int>::iterator> p = equal_range(v.begin(), v.end(), 3);
	vector<int> v1(5);
	any a = 17;
	//cout << numeric_limits<int>::max_exponent << endl;
	if (t1::pair_comparer(1, 1, 1, 2, 2, 3, 3, 5, 5)) {
		cout << "in" << endl;
	}

	return EXIT_SUCCESS;
}
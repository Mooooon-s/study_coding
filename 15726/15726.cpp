#include<iostream>
using namespace std;

int main(void) {
	double a, b, c;
	cin >> a >> b >> c;
	double result=0.0f;
	result = a / b * c;
	if (a * b / c > result) {
		result = a * b / c;
	}
	
	cout << (int)result;
	return 0;
}
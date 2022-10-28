#include<iostream>
using namespace std;

int main(void) {
	int x=0, y=0;
	int Y[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> x>>y;
	int days = 0;

	if (x != 1) {
		for (int i = 0; i < x-1; i++) {
			days += Y[i];
			//cout << days << endl;
		}
	}
	//cout << "M: " << days << endl;
	days += y;
	//cout<<"M: " << days << endl;
	//cout<<"D: " << days % 7 << endl;
	switch (days % 7) {
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	}
	return 0;
}
#include<iostream>
using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c;
	if (1 <= a, b <= 1000) {
		if (1 <= c <= 1000000) {
			d =(a * b)-c;
		}
	}
	if (d < 0) {
		cout << 0;
	}
	else {
		cout << d;
	}
}
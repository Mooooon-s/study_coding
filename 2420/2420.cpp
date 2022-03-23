#include<iostream>
using namespace std;

int main(void) {
	long a, b,c;
	cin >> a >> b;
	if (-2000000000 <= a, b <= 2000000000) {
		c=a - b;
		if (c < 0) {
			c *= -1;
		}
	}
	cout << c;
	return 0;
}
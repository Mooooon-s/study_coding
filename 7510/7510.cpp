//고급 수학
//https://www.acmicpc.net/problem/7510
#include<iostream>
using namespace std;

int main() {
	int i;
	cin >> i;
	int a, b, c;
	for (int j = 0; j < i; j++) {
		cin >> a >> b >> c;
		if (c < a) {
			int temp;
			temp = c;
			c = a;
			a = temp;
		}
		if (c < b) {
			int temp;
			temp = c;
			c = b;
			b = temp;
		}
		if ((c * c) == (a * a) + (b * b)) {
			cout << "Scenario #" << j + 1 << ":" << endl;
			cout << "yes" << endl;
		}
		else {
			cout << "Scenario #" << j + 1 << ":" << endl;
			cout << "no" << endl;
		}
		cout << endl;
	}
	return 0;
}
//사과
//https://www.acmicpc.net/problem/10833
#include<iostream>
using namespace std;

int main() {
	int N;
	int s, a,rest=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> a;
		if (a / s != 0) {
			rest += a % s;
		}
		else if (a / s == 0) {
			rest += a;
		}
	}
	cout << rest;
	return 0;
}
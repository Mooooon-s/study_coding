//고려대학교에는 공식 와인이 있다
//https://www.acmicpc.net/problem/16673
#include<iostream>
using namespace std;

int main() {
	int k, c, p;
	int result=0;
	cin >> c>>k>>p;
	for (int i = 1; i <= c; i++) {
		result += (k * i) + (p * (i * i));
	}
	cout << result;
	return 0;
}
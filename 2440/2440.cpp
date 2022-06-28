//첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	while(n!=0) {
		for (int j = n; j > 0; j--) {
			cout << '*';
		}
		cout << endl;
		n--;
	}
	return 0;
}
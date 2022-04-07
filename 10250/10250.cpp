//ACM 호텔
//https://www.acmicpc.net/problem/10250

#include<iostream>
using namespace std;

int main() {
	int T,W=0, H=0,N;
	cin >> T;
	for (int q = 0; q < T; q++) {
		int i = 0, j = 0, k = 1;
		cin >> H >> W >> N;
		for (i = 0; i < N; i++) {
			if (j < H) {
				j++;
			}
			else {
				j = 1;
				k++;
			}
		}
		cout << j * 100 + k<<endl;
	}
	return 0;
}
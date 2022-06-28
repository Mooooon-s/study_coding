//별찍기
//첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
//하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.
#include<iostream>
using namespace std;

int main(void) {
	int n,count=0;
	cin >> n;
	while (n != 0) {
		for (int j = 0; j < count; j++) {
			cout << ' ';
		}
		for (int i = n; i > 0; i--) {
			cout << '*';
		}
		cout << endl;
		n--;
		count++;
	}
	return 0;
}
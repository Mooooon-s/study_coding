//모기곱셈
//https://www.acmicpc.net/problem/6609
#include<iostream>
using namespace std;

int main() {
	//m 모기, p 번데기 l 유충
	//E는 한 모기가 낳는 알의 수이며, R과 S는 살아남는 유충과 번데기의 비율, N은 우리가 모기 수를 구하려는 시점(N주 후)이다.
	int m, p, l, e, r, s, n;
	int mp;
	while (cin >> m >> p >> l >> e >> r >> s >> n) {
		mp = m;
		for (int i = 0; i < n; i++) {
			mp = m;//지난주 모기의 수
			m = p / s;//모기로 성장한 수
			p = l / r;//번대기로 성장한 수
			l = mp * e;//유충의 수
		}
		cout << m << endl;
	}
	return 0;
}
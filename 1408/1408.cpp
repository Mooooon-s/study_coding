//도현이는 Counter Terror Unit (CTU)에서 일하는 특수요원이다. 
//도현이는 모든 사건을 정확하게 24시간이 되는 순간 해결하는 것으로 유명하다. 
//도현이는 1시간 만에 범인을 잡을 수 있어도 잡지 않는다. 정확하게 24시간이 되는 순간이 아니면 잡지 않는 CTU 특수요원이다.
//2008년 3월 3일 월요일, CTU는 새학기에 맞춰 핵폭탄을 날리겠다는 테러 정보를 입수했다. 
//CTU에서는 특수요원 도현이에게 이 임무를 맡겼다. 
//CTU의 프로그래머 준규는 이 사건의 배후가 김선영이란 것을 해킹을 통해 밝혀내었다.
//도현이는 선영이를 임무를 시작한지 정확하게 24시간이 되는 순간에 잡으려고 한다.
//만약 지금 시간이 13:52:30이고, 임무를 시작한 시간이 14:00:00 이라면 도현이에게 남은시간은 00:07:30 이다.
//모든 시간은 00:00:00 ~ 23:59:59로 표현할 수 있다. 입력과 출력에 주어지는 모든 시간은 XX:XX:XX 형태이며, 숫자가 2자리가 아닐 경우에는 0으로 채운다.
//도현이가 임무를 시작한 시간과, 현재 시간이 주어졌을 때, 도현이에게 남은 시간을 구하는 프로그램을 작성하시오.

//첫째 줄에는 현재 시간이, 둘째 줄에는 도현이가 임무를 시작한 시간이 주어진다. 임무를 시작한 시간과 현재 시간이 같은 경우는 주어지지 않는다.
//첫째 줄에 도현이가 임무를 수행하는데 남은 시간을 문제에서 주어지는 시간의 형태 (XX:XX:XX)에 맞춰 출력한다.

//---------------------------------------------------------------------------------------------------------------------------
//입력을 받고 ":"를 기준으로 분리
//분리된 값을 초로 변환
//현재시간을 시작시간으로 빼기
//뺏을때 음수가 나옴면 24시간을 더하기
//다시 초를 시간으로 변환
//00:00:00 형식으로 출력
//-----------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;

string getTime(string time) {
	string n;
	for (int i = 0; i < time.size(); i++) {
		if (time[i] != ':') {
			n.push_back(time[i]);
		}
	}
	return n;
}

void splitTime(int time, int* h, int* m, int* s) {
	int tmp=time;
	*h = tmp / 10000;
	tmp %= 10000;
	*m = tmp / 100;
	*s = tmp % 100;
}

int Ttos(int h, int m, int s) {
	int sec;
	sec = h * 60 * 60;
	sec += m * 60;
	sec += s;
	return sec;
}

void Stot(int sec,int *h,int *m,int*s) {
	int tmp = sec;
	*s = tmp % 60;
	tmp /= 60;
	*m = tmp % 60;
	*h = tmp / 60;
}

int main(void) {
	string ntime,stime;
	int a, b;
	int h, m, s;
	int nsec, ssec;
	int rest;
	cin >> ntime>>stime;
	a=stoi(getTime(ntime));
	b= stoi(getTime(stime));

	splitTime(a, &h, &m, &s);
	nsec = Ttos(h, m, s);
	splitTime(b, &h, &m, &s);
	ssec = Ttos(h, m, s);
	rest=ssec - nsec;

	if (rest < 0) {
		rest=86400 + rest;
	}

	Stot(rest, &h, &m, &s);

	cout.width(2);
	cout.fill('0');
	cout << h << ":";
	cout.width(2);
	cout.fill('0');
	cout << m<<":";
	cout.width(2);
	cout.fill('0');
	cout << s;

	return 0;
}
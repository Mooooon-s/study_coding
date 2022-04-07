//핸드폰 요금
//https://www.acmicpc.net/problem/1267
#include<iostream>
#include<vector>
using namespace std;

vector<int> Ycall(vector<int> a, int b) {
	if (b / 30 == 0) {
		a.push_back(10);
		//cout << 10<<endl;
	}
	else {
		if (b % 30 < 30) {
			a.push_back(10* ((b / 30) + 1));
			//cout << 10 * ((b / 30) + 1)<<endl;
		}
	}
	return a;
}

vector<int> Mcall(vector<int> a, int b) {
	if (b / 60 == 0) {
		a.push_back(15);
		//cout << 15 << endl;
	}
	else {
		if (b % 60 < 60) {
			a.push_back(15 * ((b / 60) + 1));
			//cout << 15 * ((b / 60) + 1) << endl;
		}
	}
	return a;
}

int add(vector<int> a) {
	int r=0;
	for (int i = 0; i < a.size(); i++) {
		r+=a.at(i);
	}
	return r;
}

pair<string, int> compare(int a,int b) {
	if (a<b) {
		return make_pair("Y", a);
	}
	else if(a>b) {
		return make_pair("M", b);
	}
	else {
		return make_pair("Y M", a);
	}
}

int main() {
	int N;
	vector<int> a,c;
	int b;
	int r1=0, r2=0;
	pair<string, int> fin;
	cin >>N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a=Ycall(a, b);
		c = Mcall(c, b);
	}
	r1 = add(a);
	r2 = add(c);
	//cout << r1<<endl<<r2<<endl;
	fin = compare(r1, r2);
	cout << fin.first<<" " << fin.second << endl;
	return 0;
}
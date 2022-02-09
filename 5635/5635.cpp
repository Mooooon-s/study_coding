#include<iostream>
#include<string>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;

using Tuple=tuple<string, int, int, int>;
vector<Tuple> v;

bool cmp(Tuple &a, Tuple &b) {
	int ad= get<1>(a);
	int am = get<2>(a);
	int ay = get<3>(a);
	int bd = get<1>(b);
	int bm = get<2>(b);
	int by = get<3>(b);

	if (ay == by) {
		if (am == bm) {
			return ad > bd;
		}
		return am > bm;
	}
	return ay > by;
}

int main() {
	int n;
	cin >> n;
	string name;
	int D, M, Y;
	
	for (int i = 0; i < n; i++) {
		cin >> name >> D >> M >> Y;
		v.push_back(make_tuple(name, D, M, Y));
	}

	sort(v.begin(),v.end(), cmp);
	string min, max;
	min = get<0>(v.at(0));
	max = get<0>(v.at(n-1));
	cout << min << endl;
	cout << max;
	return 0;
}
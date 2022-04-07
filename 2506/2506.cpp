//점수계산
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a;
	int b, c;
	cin >> b;
	int bouns=1,result=0;
	for (int i = 0; i < b; i++) {
		cin >> c;
		a.push_back(c);
	}
	for (int j = 0; j < a.size(); j++) {
		if (a.at(j) == 1) {
			result += bouns;
			bouns++;
		}
		else {
			bouns = 1;
		}
	}
	cout << result;
}
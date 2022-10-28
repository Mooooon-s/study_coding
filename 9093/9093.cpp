#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	string s;
	stack<char> a;
	int n;

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		s += '\n';
		for (auto c : s) {
			if (c == ' ' || c == '\n') {
				while (!a.empty()) {
					cout << a.top();
					a.pop();
				}
				cout << c;
			}
			else
			{
				a.push(c);
			}
		}
	}
	return 0;
}
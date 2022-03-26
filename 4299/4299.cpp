#include<iostream>
using namespace std;

int main(void) {
	int sum,mus,a,b;
	cin >> sum >> mus;
	a = (sum + mus) / 2;
	b = sum - a;

	if (sum-mus<0 || (sum+mus)%2!=0) {
		cout << "-1"<<endl;
	}
	else {
		if (a > b) {
			cout << a<<" " << b;
		}
		else if (b > a) {
			cout << b<<" " << a;
		}
		else {
			cout << a<<" " << b;
		}
	}
}
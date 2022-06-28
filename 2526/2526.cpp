//2526 싸이클
#include<iostream>
using namespace std;
int getnext(int f, int n, int p) {
	return f * n % p;
}

int main() {
	int n, p;
	int first,tmp;
	int arr[98] = {0};
	int i = 1;
	cin >> n >> p;
	first = n * n % p;
	arr[first]=i;
	tmp = first;
	i++;
	while (1) {
		first = getnext(tmp, n, p);
		if (arr[first]!=0) {
			break;
		}
		arr[first]=i;
		tmp = first;
		i++;
	}
	cout << i-arr[first];
}
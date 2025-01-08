#include <iostream>

using namespace std;

int main() {
	int n;
	int _max=0;
	
	cin >> n;
	int* _array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> _array[i];
	}

	int _min = _array[0];
	for (int i = 0; i < n; i++) {
		if (_array[i] < _min) _min = _array[i];
		_max = max(_max, _array[i] - _min);
	}

	cout << _max;
	return 0;
}
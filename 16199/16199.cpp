#include<iostream>
using namespace std;

class age {
	int by, bm, bd;
	int ny, nm, nd;
	int x_age, y_age, z_age;
public:
	void inputage() {
		cin >> by >> bm >> bd;
		cin >> ny >> nm >> nd;
	};

	void getx_age() {
		int a;
		a = (ny - by);
		if (a == 0) {
			x_age = 0;
		}
		else if (nm > bm && a!=0) {
			x_age = a;
		}
		else if (nm < bm && a != 0) {
			x_age = a-1;
		}
		else if (nm == bm && a != 0) {
			if (nd < bd) {
				x_age = a - 1;
			}
			else {
				x_age = a;
			}
		}
	}

	void gety_age() {
		y_age = (ny - by) + 1;
	}

	void getz_age() {
		z_age = (ny - by);
	}

	int* getage() {
		int* a=new int[3];
		a[0] = x_age;
		a[1] = y_age;
		a[2] = z_age;
		return a;
	}
};

int main(void) {
	age a;
	int* b;
	a.inputage();
	a.getx_age();
	a.gety_age();
	a.getz_age();
	b = a.getage();
	for (int i = 0; i < 3; i++) {
		cout << b[i] << endl;
	}
	return 0;
}
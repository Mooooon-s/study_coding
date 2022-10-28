#include<iostream>
using namespace std;

int Room(int x, int k);

int main(void) {
	int N, K;
	int S, Y;
	double M[6] = {0}, W[6] = { 0 };
	int r[5] = { 0 };
	int room=0;


	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		if (S == 0) {
			//cout << "man grade:" << Y << endl;
			M[Y-1]++;
		}

		if(S == 1) {
			W[Y-1]++;
		}
	}

	r[0] = ((M[0] + W[0]) + (M[1] + W[1]));	//1,2 grade
	r[1] = (M[2] + M[3]);					//3,4 grade man
	r[2]= (W[2] + W[3]);					//3,4 grade woman
	r[3] = (M[4] + M[5]);					//5,6 grade man
	r[4] = (W[4] + W[5]);					//5,6 hrade woman

	for (auto R : r) {
		//cout<<"there are : " << R << endl;
		room += Room(R, K);
		//cout << "set Room: " << room<<endl;
	}
	
	cout << room;
	return 0;
}

int Room(int x, int k) {
	int result = 0;
	if (x != 0) {
		result = x / k;
		//cout << "Room: " << result << endl;
		if (x % k != 0) {
			//cout << "rest: " << x % k << endl;
			result++;
			//cout << "Room: " << result << endl;
		}
	}

	return result;
}
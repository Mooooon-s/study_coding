//입력받은 수를 정렬하는 문제
//O(n^2)인 정렬로 문제를 풀 수있음
//버블 정렬 삽입 정렬 두가지 방법으로 문제를 풀었음

////삽입정렬
//#include<iostream>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	int i,j,key;
//	for ( i = 1; i < n; i++) {
//		key = arr[i];
//		for ( j = i - 1; j >= 0 && arr[j] > key; j--) {
//			arr[j + 1] = arr[j];
//		}
//		arr[j + 1] = key;
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << "\n";
//	}
//	return 0;
//}
//--------------------------------------------------------------------
//버블 정렬
//#include<iostream>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//	int *arr =new int[n];
//	int tmp=0;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = n-1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (arr[j] > arr[j+1]) {
//				 tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << "\n";
//	}
//	return 0;
//}
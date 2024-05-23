#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[1001] = {};
    int N,P,L;
    int cnt =0;
    cin >> N >> L;

    for(int i=0;i<N;i++)
        {
            cin >> arr[i];
        }

    sort(arr,arr+N);

    int now = arr[0];
    for(int i=0;i<N;i++)
        {
            if(L <= arr[i] - now)
            {
                cnt++;
                now = arr[i];
            }
        }
    
    cout << cnt+1;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n+1] = {0,};
    int cnt=0;

    for(int i=0;i < n ;i++)
        {
            int idx;
            cin >> idx;
            arr[idx] = i;
        }

    for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[i+1])
                cnt++;
        }
    
    cout << cnt;
    
    return 0;
}
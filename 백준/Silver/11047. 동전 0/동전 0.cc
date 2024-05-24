#include <iostream>

using namespace std;

int main() {
    int N , K;
    int cnt=0;
    cin >> N >> K;

    int* arr = new int[N];

    for(int i=0;i<N;i++)
        {
            cin >> arr[i];
        }

    for(int i=N-1;i>=0;i--)
        {
            if(K/arr[i]!=0)
            {
                cnt+=(K/arr[i]);
                K%=arr[i];
            }
        }

    cout << cnt;
    
    return 0;
}
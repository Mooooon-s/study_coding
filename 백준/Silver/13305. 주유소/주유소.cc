#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long* A = new long long[N];
    long long* B = new long long[N-1];

    for(int i=0;i<N-1;i++)
        {
            cin >> B[i];
        }
    
    for(int i=0;i<N;i++)
        {
            cin >>A[i];
        }

    long long now = A[0];

    long long result = now*B[0];

    for(int i=1;i<N-1;i++)
        {
            if(now > A[i])
            {
                now = A[i];
                result+=now * B[i];
            }
            else{
                result+=now * B[i];
            }
        }
    
    cout << result;
    return 0;
}
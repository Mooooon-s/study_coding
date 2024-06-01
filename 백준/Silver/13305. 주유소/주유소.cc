#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int* A = new int[N];
    int* B = new int[N-1];

    for(int i=0;i<N-1;i++)
        {
            cin >> B[i];
        }
    
    for(int i=0;i<N;i++)
        {
            cin >>A[i];
        }

    int now = A[0];

    int result = now*B[0];

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
    
    std::cout << result;
    return 0;
}
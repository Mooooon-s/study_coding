#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    if(a>b)
        return true;
    return false;
}

int main() {

    int N;

    cin >> N;
    int* A = new int[N];
    int* B = new int[N];

    for(int i=0;i<N;i++)
        {
            cin >> A[i];
        }

    for(int i=0;i<N;i++)
        {
            cin >> B[i];
        }

    sort(B,B+N);
    sort(A,A+N,cmp);
    int result =0;
    for(int i=0;i<N;i++)
        {
            result+=(A[i]*B[i]);
        }

    cout << result;
    
    return 0;
}
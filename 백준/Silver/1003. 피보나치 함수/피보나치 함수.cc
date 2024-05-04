#include <iostream>

using namespace std;

int fibo[50] = {0,1,};

int fibonacci(int n)
{
    if(n==1 || n==0)
        return fibo[n];
    else if (fibo[n]==0)
        fibo[n] = fibonacci(n-1) + fibonacci(n-2);
    return fibo[n];
}

int main() {
    int t;
    cin >> t;

    for(int i=0;i<t;i++)
        {   
            int a ;
            cin >> a;
            if(a == 0)
                cout << "1 0"<<endl;
            else
                cout << fibonacci(a-1) << ' ' << fibonacci(a) << '\n';
        }
    
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n , m;
    cin >> n >> m;

    long long arr[n];
    long long max=0;
    for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            if(max < arr[i])
                max = arr[i];
        }

    long long left,right,mid,total;
    left = 0;
    right = max;
    total = 0;
    
    while(left <= right)
    {
        long long temp=0;
        mid = (left + right) /2;
        
        for(int i=0;i<n;i++)
            {
                long long a = arr[i] - mid;
                if(a > 0)
                    temp += a;
            }
        
        if(temp < m)
        {
            right  = mid - 1;
        }
        else if(temp >= m)
        {
            left = mid + 1;   
            total = mid;
        }
    }

    cout << total;
    return 0;
}
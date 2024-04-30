#include <iostream>

using namespace std;

int main() {
    int k;
    int n;
    long long len;
    cin >> k >> n;

    long long arr[k] = {0,};
    long long max=0;
    
    for(int i=0;i<k;i++)
    {
        cin>> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    long long left, right, mid;
    left = 1;
    right = max;
    len = 0;
    while(left <= right)
    {
        int temp=0;
        mid = (left+right) / 2;
        for(int i=0;i<k;i++)
        {
            temp +=arr[i] / mid;        
        }

        if(temp < n)
        {
            right = mid-1;
        }
        else if(temp >= n)
        {
            left = mid+1;
            if(len < mid)
                len = mid;
        }
    }

    cout << len;
    
    return 0;
}
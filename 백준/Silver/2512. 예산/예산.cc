#include <iostream>

using namespace std;

int main() {
    long long n , m;
    cin >> n;
    long long arr[n];
    long long max =0;
    
    for(int i=0; i<n ;i++)
        {
            cin >> arr[i];
            if(max < arr[i])
                max = arr[i];
        }

    cin >> m;

    long long left,right,mid,total;
    left = 0;
    right = max;

    while(left<=right)
        {
            mid = (left + right) / 2;
            long long temp =0;

            for(int i=0;i<n;i++)
                {
                    if(arr[i] < mid)
                        temp += arr[i];
                    else
                        temp +=mid;
                }

            if(temp <= m)
            {
                total = mid;
                left = mid +1;
            }
            else
            {
                right = mid-1;
            }
        }
    cout << total;
    return 0;
}
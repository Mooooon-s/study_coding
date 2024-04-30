#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    int n,m;
    vector<int> a;

    cin >>t;

    for(int i=0;i<t;i++)
    {
        cin >>n;
        a.assign(n,0);
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        cin >>m;

        sort(a.begin(),a.end());
        
        for(int j=0;j<m;j++)
        {
            int target = 0;
            int high = a.size()-1;
            int low =0;
            int flag = 0;

            cin >> target;
            while(low <= high)
            {
                int mid = (low + high) /2;
                if(target == a[mid])
                {
                    flag=1;
                    cout << 1 << "\n";
                    break;
                }
                else if(target < a[mid])
                {
                    high = mid-1;
                }
                else if(target > a[mid])
                {
                    low = mid+1;
                }
            }

            if(flag ==0)
                cout <<0 << "\n";
        }
    }

    return 0;
}
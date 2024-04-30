#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> c,d;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin>>n;
    c.assign(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }

    cin>>m;
    d.assign(m,0);
    for(int i=0;i<m;i++)
    {
        cin>>d[i];
    }

    sort(c.begin(),c.end());
    for(int i=0;i<m;i++)
    {
        int target = d[i];
        int low =0;
        int high = c.size()-1;
        
        while(1)
        {
            int mid = (high + low) /2;
            if(low > high)
            {
                cout<<"0";
                break;
            }
            if(target == c[mid] )
            {
                cout<<"1";
                break;
            }
            else if(target < c[mid])
            {
                high = mid-1;
            }
            else if(target > c[mid])
            {
                low = mid+1;
            }
        }
        cout<<" ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    vector<pair<int,int>> XY;
    cin >>n;
    for(int i=0;i<n;i++)
        {
            int x,y;
            cin >>x>>y;
            
            XY.push_back(make_pair(y,x));
        }

    sort(XY.begin(),XY.end());

    for(auto a : XY)
        {
            cout << a.second<<" " << a.first<<"\n";
        }
    
    return 0;
}
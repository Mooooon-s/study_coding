#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    vector<int> level;
    long long n;

    double cut;
    double sum=0;
    cin >>n;

    for(int i=0;i<n;i++)
        {
            int temp;
            cin >> temp;
            level.push_back(temp);
        }

    if(n==0)
        cout << 0;
    else
    {
        sort(level.begin(),level.end());

        cut = (float)n * 0.15;
        cut = round(cut);
    
        //for(int i=0;i<cut;i++)
        //    {
        //        level.erase(level.begin());     
        //        level.pop_back();
        //    }
    
        //for(auto l : level)
        //    {
        //        sum+=l;
        //    }

        for(int i=cut ; i < n-cut;i++)
            {
                sum+=level[i];
            }
        
        cout << round(sum/(level.size()-(cut*2)));
    }

    return 0;
}
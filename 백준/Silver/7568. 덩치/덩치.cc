#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> h;
vector<pair<int,int>> t;

int main() {
    int n;
    int x,y;
    cin >> n;
    
    for(int i=0;i<n;i++)
        {
            cin >>x>>y;
            h.push_back(make_pair(x,y));
        }

    
    for(int i=0;i<n;i++)
        {
            int a=0;
            int b=0;
            for(int j=0;j<n;j++)
                {
                    if(i==j)
                        continue;
                    if(h[i].first > h[j].first && h[i].second > h[j].second )
                        a++;
                    else if(h[i].first < h[j].first && h[i].second < h[j].second )
                        continue;
                    else
                    {
                        b++;    
                    }
                }
            t.push_back(make_pair(a,b));
        }

    for(auto tier : t)
        {
            cout << n - tier.first - tier.second << " ";
        }

    return 0;
}
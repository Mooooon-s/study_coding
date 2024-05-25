#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N,S,T;
    int cnt=0;
    vector<pair<int,int>> Class;
    priority_queue<int,vector<int>,greater<>> tmp ;
    
    cin >> N ;

    for(int i=0;i<N;i++)
        {
            cin >> S >> T;
            Class.push_back(make_pair(S,T));
        }

    sort(Class.begin(),Class.end());

    tmp.push(Class[0].second);
    for(int i=1;i<N;i++)
        {
            pair<int,int> now = Class[i];
            if(tmp.top() <= now.first)
            {
                tmp.pop();
                tmp.push(now.second);
            }
            else
            {
                tmp.push(now.second);
            }
        }

    cout << tmp.size();
    
    return 0;
}

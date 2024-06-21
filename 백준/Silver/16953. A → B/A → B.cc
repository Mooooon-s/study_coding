#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<long long, int>> q;
int dist=0;

int main(void)
{
    long long a,b;
    cin >> a>> b;

    q.push({a,dist});

    while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            
            if(cur.first == b)
            {
                cout << cur.second+1;
                return 0;
            }

            if(2*cur.first <= b)
            {
                q.push({2*cur.first,cur.second+1});
            }
            if(10*cur.first +1 <=b)
            {
                q.push({10*cur.first+1, cur.second+1});
            }
        }

    cout <<-1;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define MAX 100001


queue<pii> q;
bool visited[MAX];


int main() {
    int n,k;
    cin >> n >> k;

    q.push({n,0});
    visited[n]=true;

    while(!q.empty())
        {
            auto a = q.front(); q.pop();
            
            if(a.first==k){
                cout<< a.second;
                return 0;
            }
            if( 2*a.first < MAX && !visited[2*a.first]){
                q.push({2*a.first,a.second+1});
                visited[2*a.first]=true;
            }
            if( a.first+1 < MAX && !visited[a.first+1])
            {
                q.push({a.first+1,a.second+1});
                visited[a.first+1]=true;
            }
            if( a.first-1 >= 0 && !visited[a.first-1])
            {
                q.push({a.first-1,a.second+1});
                visited[a.first-1]=true;
            }
        }
    
    return 0;
}
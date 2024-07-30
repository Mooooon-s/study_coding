#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define MAX 1000001

bool visited[MAX];

queue<pii> q;

int main(void){
    int a,b;
    cin >> a >> b;

    q.push({a,0});
    visited[0]=true;

    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(s.first==b){
            cout << s.second;
            return 0;
        }
        
        
        if(s.first+1 < MAX && !visited[s.first+1]){
            q.push({s.first+1,s.second+1});
            visited[s.first+1]=true;
        }
        
        if(s.first*2 < MAX && !visited[s.first*2]){
            q.push({s.first*2,s.second+1});
            visited[s.first*2]=true;
        }

    }
    return 0;
}
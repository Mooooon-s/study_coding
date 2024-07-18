#include <bits/stdc++.h>

using namespace std;

#define MAX 101

typedef pair<int,int> pii;

vector<int> adj[MAX];

queue<int> q;

bool visited[MAX];

int main(){
    int n,w;
    cin >> n >> w;

    for(int i=1;i<=w;i++){
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(1);
    visited[1]=true;

    int cnt=0;
    while(!q.empty()){
        auto s = q.front(); q.pop();
        for(auto u : adj[s]){
            if(visited[u])continue;
            visited[u]=true;
            q.push(u);
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}
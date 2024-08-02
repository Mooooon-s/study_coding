#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

typedef pair<int,int> pii;

vector<int> adj[MAX];
queue<int> q;
bool dfsvis[MAX];
bool bfsvis[MAX];

int n , m ,v;

int flag =false;

void dfs(int a,int level){
    if(dfsvis[a])return;
    cout << a << ' ';
    dfsvis[a]=true;
    for(auto u : adj[a]){
        dfs(u,level+1);
    }
}

void bfs(int a){
    q.push(a);
    
    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(bfsvis[s])continue;
        cout << s << ' ';
        bfsvis[s]=true;
        for(auto u : adj[s]){
            q.push(u);
        }
    }
}


int main(){
    cin >> n >> m >> v;

    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<MAX;i++){
        if(!adj[i].empty()){
            sort(adj[i].begin(),adj[i].end());
        }
    }

    dfs(v,1);
    cout << '\n';
    bfs(v);
    
    return 0;
}
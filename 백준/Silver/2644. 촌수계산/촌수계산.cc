#include<bits/stdc++.h>

using namespace std;

#define MAX 101

vector<int> adj[MAX];

bool visited[MAX];
int a, b;

bool flag=false;

void dfs(int at,int level){
    if(at==b){
        cout << level;
        flag=true;
        return;
    }
    if(flag)return;
    if(visited[at])return;
    visited[at]=true;
    for(auto s : adj[at]){
        dfs(s,level+1);
    }
    visited[at]=false;
};

int main(){
    int n;
    cin >> n;
    cin >> a >> b;
    int m;
    cin >> m;

    for(int i=0;i<m;i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(a,0);

    if(!flag)
        cout <<-1;

    return 0;
}
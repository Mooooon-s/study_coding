#include<bits/stdc++.h>

using namespace std;

#define MAX 1000001

typedef pair<int,int> pii;

vector<int> adj[MAX];

queue<pii> q;

vector<int> city;

bool visited[MAX];

int n, m , k , x;

int main(){
    cin >> n >> m >> k >> x;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    q.push({x,0});
    
    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(visited[s.first])continue;
        visited[s.first]=true;
        if(s.second == k ){
            city.push_back(s.first);
            continue;
        }
        for(auto u : adj[s.first]){
            q.push({u,s.second+1});
        }
    }

    sort(city.begin(),city.end());
    if(city.size()==0)cout << -1;
    else{
        for(int i=0;i<city.size();i++){
            cout << city[i]<<"\n";
        }
    }


    return 0;
}
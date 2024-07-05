#include <bits/stdc++.h>

using namespace std;

#define MAX 200002

bool visited[MAX];

int dist[MAX];

queue<int> q;

int main(){
    int n , k;
    cin >> n >> k;
    
    visited[n]=true;
    dist[n]=0;
    q.push(n);

    while(!q.empty()){
        auto s =  q.front(); q.pop();
        if(s==k){
            cout << dist[s];
            break;
        }

        if(2*s<=MAX && !visited[2*s]){
            q.push(2*s);
            visited[2*s]=true;
            dist[2*s]=dist[s];
        }

        if(s-1>=0 && !visited[s-1]){
            q.push(s-1);
            visited[s-1]=true;
            dist[s-1]=dist[s]+1;
        }
        
        if(s+1 <= MAX && !visited[s+1]){
            q.push(s+1);
            visited[s+1]=true;
            dist[s+1]=dist[s]+1;
        }
        
    }
    
    return 0;
}
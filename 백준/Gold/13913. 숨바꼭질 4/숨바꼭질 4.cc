#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef pair<int,int> pii;

bool visited[MAX];
pii dist[MAX];

queue<int> q;

vector<int> v;

int main(void){
    int n,k;
    cin >> n >> k;

    visited[n]=true;
    dist[n]={0,-1};
    q.push(n);
    
    while(!q.empty()){
        int s = q.front(); q.pop();
        if(s==k){
            cout << dist[s].first << '\n';
            int a=s;
            v.push_back(a);
            while(1){
                if(dist[a].second==-1)
                    break;

                v.push_back(dist[a].second);
                a = dist[a].second; 
            }

            while(!v.empty()){
                cout << v.back()<<' '; v.pop_back();
            }
            return 0;
        }
        
        if( 2*s <=MAX-1 && !visited[2*s] ){
            visited[2*s]=true;
            dist[2*s]={dist[s].first+1,s};
            q.push(2*s);
        }

        if(s-1 >=0 && !visited[s-1]){
            visited[s-1]=true;
            dist[s-1]={dist[s].first+1,s};
            q.push(s-1);
        }

        if(s+1 <= MAX-1 && !visited[s+1]){
            visited[s+1]=true;
            dist[s+1]={dist[s].first+1,s};
            q.push(s+1);
        }
    }
    return 0;
}
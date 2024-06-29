#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

bool visited[MAX];
int dist[MAX];
queue<int> q;

int main(void){
    int f,g,s,u,d;
    cin >> f >> s >> g >> u >> d;

    visited[s]=true;
    dist[s]=0;
    q.push(s);

    while(!q.empty()){
        auto a = q.front(); q.pop();
        if(a==g){
            cout << dist[a];
            return 0;
        }
        if(a+u <=f && !visited[a+u]){
            visited[a+u]=true;
            dist[a+u]=dist[a]+1;
            q.push(a+u);
            //cout << "goto " << a+u <<'\n';
        }
        if(a-d >=1 && !visited[a-d]){
            visited[a-d]=true;
            dist[a-d]=dist[a]+1;
            q.push(a-d);

            //cout << "goto " << a-d<<'\n';
        }
    }

    //for(int i=1;i<f;i++){
    //    cout << visited[i] << '\n';
    //}

    cout << "use the stairs";
    
    return 0;
}
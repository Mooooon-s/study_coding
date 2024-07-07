#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct siii {
    int a;
    int b;
    int c;
};

#define MAX 1001

vector<pii> hadj[MAX][MAX];

queue<siii> q;

bool visited[MAX][MAX][11];
int dist[MAX][MAX][11];

int board[MAX][MAX];

int main(void){
    int n,m,k;

    cin >>n>>m>>k;

    for(int i=1;i<=n;i++){
        string s;
        cin >>s;
        for(int j=1;j<=m;j++){
            board[i][j]=s[j-1]-'0';

            if(i-1>=1){
                hadj[i][j].push_back({i-1,j});
                hadj[i-1][j].push_back({i,j});
            }
            if(j-1>=1){
                hadj[i][j].push_back({i,j-1});
                hadj[i][j-1].push_back({i,j});
            }
        }
    }

    siii p;
    p.a=1; p.b=1; p.c=0;
    visited[1][1][0]=true;
    dist[1][1][0]=1;
    q.push(p);
    
    while(!q.empty()){
        auto s = q.front(); q.pop();

        if(s.a==n && s.b == m){
            cout << dist[s.a][s.b][s.c];
            return 0;
        }
        for(auto u : hadj[s.a][s.b]){
            int a = u.first;
            int b = u.second;
            if(board[a][b]==1 && s.c<k ){
                if(visited[a][b][s.c+1])continue;
                visited[a][b][s.c+1]=true;
                dist[a][b][s.c+1]= dist[s.a][s.b][s.c]+1;
                siii p1;
                p1.a =a; p1.b=b; p1.c = s.c+1;
                q.push(p1);
            }
            if(board[a][b]==0){
                if(visited[a][b][s.c])continue;
                visited[a][b][s.c]=true;
                dist[a][b][s.c]=dist[s.a][s.b][s.c]+1;
                siii p2;
                p2.a=a; p2.b=b; p2.c=s.c;
                q.push(p2);
            }
        }
    }

    cout << -1;
    
    return 0;
}
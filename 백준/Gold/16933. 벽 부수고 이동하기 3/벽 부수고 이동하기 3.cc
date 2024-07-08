#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

typedef pair<int,int> pii;

struct siiib {
    int a;
    int b;
    int c;
    bool d;
    int e;
};

vector<pii> adj[MAX][MAX];

bool visited[MAX][MAX][11];
int dist[MAX][MAX][11];

queue<siiib> q;

int board[MAX][MAX];

int main(void){
    int n,m,k;
    cin >> n >> m >> k;
    
    for(int i=1;i<=n;i++){
        string s;
        cin >>s;
        for(int j=1;j<=m;j++){
            board[i][j]=s[j-1]-'0';
            if(i-1>=1){
                adj[i][j].push_back({i-1,j});
                adj[i-1][j].push_back({i,j});
            }

            if(j-1>=1){
                adj[i][j].push_back({i,j-1});
                adj[i][j-1].push_back({i,j});
            }
        }
    }

    dist[1][1][0]=1;   
    visited[1][1][0]=true;

    siiib p;
    p.a =1; p.b=1; p.c=0; p.d=true; p.e=0;
    q.push(p);

    while(!q.empty()){
        auto s = q.front(); q.pop();

        if(s.a==n && s.b == m){
            cout << dist[s.a][s.b][s.c];

            // for(int k=0;k<11;k++){
            //     for(int i=1;i<=n;i++){
            //         for(int j=1;j<=m;j++){
            //             cout << dist[i][j][k];
            //         }
            //         cout << '\n';
            //     }
            //     cout << '\n';
            // }

            
            return 0;
        }

        for(auto u : adj[s.a][s.b]){
            int a= u.first;
            int b= u.second;
            int c= s.c;
            int d= s.d;


            if(board[a][b]==1){
                if(s.c==k)continue;
                if(s.d==true){
                    if(visited[a][b][s.c+1])continue;    
                    visited[a][b][s.c+1]=true;
                    dist[a][b][s.c+1]=dist[s.a][s.b][s.c]+s.e+1;
                    
                    siiib p1;
                    p1.a=a; p1.b=b; p1.c=s.c+1; p1.d=!d; p1.e = 0;
                    q.push(p1);
                }
                else if(s.d==false){
                    siiib p1;
                    p1.a=s.a; p1.b=s.b; p1.c=s.c; p1.d=!d; p1.e=1;
                    q.push(p1);
                }
            }
            if(board[a][b]==0){
                if(visited[a][b][c])continue;
                visited[a][b][c]=true;
                dist[a][b][c]=dist[s.a][s.b][s.c]+1;
                
                siiib p2;
                p2.a=a; p2.b=b; p2.c=c; p2.d=!d; p2.e=0;
                q.push(p2);
            }
        }
    }

    cout << -1;
    
    return 0;
}
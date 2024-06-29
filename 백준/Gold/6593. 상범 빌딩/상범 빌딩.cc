#include <bits/stdc++.h>

using namespace std;

#define MAX 31

struct piii {
    int a;
    int b;
    int c;
};

vector<piii> adj[MAX][MAX][MAX];
queue<piii> q;

bool visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

char board[MAX][MAX][MAX];

int main(void){
    while(1){
        int l,r,c;
        cin >> l >> r >> c;

        if(l==0 && r==0 && c==0){
            return 0;
        }

        for(int t=1;t<=l;t++){
            for(int i=1;i<=r;i++){
                for(int j=1;j<=c;j++){
                    visited[t][i][j]=false;
                    dist[t][i][j]=-1;
                    adj[t][i][j].clear();
                    board[t][i][j]=0;
                }
            }
        }

        while(!q.empty()) q.pop();

        
        for(int t=1;t<=l;t++){
            for(int i=1;i<=r;i++){
                string s;
                cin>>s;
                for(int j=1;j<=c;j++){
                    board[t][i][j]=s[j-1];
                    if(board[t][i][j]=='S'){
                        piii p1;
                        p1.a=t; p1.b=i; p1.c=j;
                        visited[t][i][j]=true;
                        dist[t][i][j]=0;
                        q.push(p1);

                        if(t-1>=1 && board[t-1][i][j]!='#'){
                            piii p1,p2;
                            p1.a=t-1; p1.b=i; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t-1][i][j].push_back(p2);
                        }
                        if(i-1>=1 && board[t][i-1][j]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i-1; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i-1][j].push_back(p2);
                        }
                        if(j-1>=1 && board[t][i][j-1]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i; p1.c=j-1;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i][j-1].push_back(p2);
                        }
                    }

                    if(board[t][i][j]=='.'){
                        if(t-1>=1 && board[t-1][i][j]!='#'){
                            piii p1,p2;
                            p1.a=t-1; p1.b=i; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t-1][i][j].push_back(p2);
                        }
                        if(i-1>=1 && board[t][i-1][j]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i-1; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i-1][j].push_back(p2);
                        }
                        if(j-1>=1 && board[t][i][j-1]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i; p1.c=j-1;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i][j-1].push_back(p2);
                        }
                    }
                    if(board[t][i][j]=='E'){
                        if(t-1>=1 && board[t-1][i][j]!='#'){
                            piii p1,p2;
                            p1.a=t-1; p1.b=i; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t-1][i][j].push_back(p2);
                        }
                        if(i-1>=1 && board[t][i-1][j]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i-1; p1.c=j;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i-1][j].push_back(p2);
                        }
                        if(j-1>=1 && board[t][i][j-1]!='#'){
                            piii p1,p2;
                            p1.a=t; p1.b=i; p1.c=j-1;
                            p2.a=t; p2.b=i; p2.c=j;
                            adj[t][i][j].push_back(p1);
                            adj[t][i][j-1].push_back(p2);
                        }
                    }
                }
            }
        }
        // int mx=0;
        int flag=0;

        while(!q.empty()){
            auto s = q.front(); q.pop();
            if(board[s.a][s.b][s.c]=='E'){
                cout << "Escaped in " << dist[s.a][s.b][s.c] << " minute(s).\n";
                flag=1;
                break;
            }
            for(auto u : adj[s.a][s.b][s.c]){
                int a=u.a;
                int b=u.b;
                int c=u.c;
                if(visited[a][b][c])continue;
                visited[a][b][c]=true;
                dist[a][b][c]=dist[s.a][s.b][s.c]+1;
                piii p1;
                p1.a=a;
                p1.b=b;
                p1.c=c;
                q.push(p1);
                // mx=max(mx,dist[a][b][c]);
            }
        }

        // for(int t=1;t<=l;t++){
        //     for(int i=1;i<=r;i++){
        //         for(int j=1;j<=c;j++){
        //             //visited[t][i][j]=false;
        //             cout << dist[t][i][j] << ' ';
        //             //adj[t][i][j].clear();
        //             //board[t][i][j]=0;
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }

        if(!flag)
            cout<< "Trapped!\n";
    }
    
    return 0;
}
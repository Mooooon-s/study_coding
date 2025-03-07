#include<bits/stdc++.h>
#define MAX 1001

using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
bool visited[MAX][MAX];
queue<pii> q;


int main(){
    int n;
    cin >> n;

    char board[MAX][MAX];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]=='*')
            {                
                if(i-1 > 0 && board[i-1][j]=='*'){
                    adj[i-1][j].push_back({i,j});
                    adj[i][j].push_back({i-1,j});
                }
                
                if(j-1 > 0 && board[i][j-1]=='*'){
                    adj[i][j-1].push_back({i,j});
                    adj[i][j].push_back({i,j-1});
                }
            }
        }
    }
    
    int flag=false;
    pii head;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]=='*')
            {
                head = pii(i,j);
                flag=true;
                break;
            }
        }
        if(flag) break;
    }

    //cout << head.first << ' ' << head.second;

    pii heart = pii(head.first+1,head.second);

    int x = heart.first;
    int y = heart.second;
    visited[x][y]=true;

    cout << x << ' ' << y<< '\n';

    pii root[3]={ {x,y-1},{x,y+1},{x+1,y} };
    pii leg[2];
    for(int i=0;i<3;i++){
        //cout << "pos: " << root[i].first << ' ' << root[i].second << '\n';
        int cnt =1;
        q.push(root[i]);
        visited[root[i].first][root[i].second]=true;
        while(!q.empty()){
            auto s = q.front(); q.pop();
            for(auto u : adj[s.first][s.second]){
                int a = u.first;
                int b = u.second;
                if(visited[a][b])continue;
                //cout << a << ' ' << b << '\n';
                q.push({a,b});
                visited[a][b]=true;
                cnt++;
            }
        }

        cout << cnt << ' ';

        if(i==2){
            leg[0]= {x+(cnt+1), y-1 };
            leg[1]= { x + (cnt+1),y+1 };
        }
    }

    q = queue<pii>();
    for(int i=0;i<2;i++){
        int cnt=1;
        q.push(leg[i]);
        visited[leg[i].first][leg[i].second]=true;
        while(!q.empty()){
            auto s = q.front(); q.pop();
            for(auto u : adj[s.first][s.second]){
                int a= u.first;
                int b= u.second;
                if(visited[a][b])continue;
                q.push({a,b});
                visited[a][b]=true;
                cnt++;
            }
        }

        cout << cnt<<' ';
    }

    return 0;    
}
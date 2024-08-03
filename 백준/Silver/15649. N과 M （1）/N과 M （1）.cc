#include <bits/stdc++.h>

using namespace std;


#define MAX 9

int arr[MAX];
int used[MAX];
int n , m;

void dfs(int idx){
    if(idx == m){
        for(int i=0;i< m ;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++){
        if(used[i]==0){
            arr[idx]=i;
            used[i]=1;
            dfs(idx+1);
            used[i]=0;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0);

    
    return 0;
}
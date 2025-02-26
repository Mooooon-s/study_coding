#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;

        //cout<< "input : " << x <<'\n';

        if(x>0){
            q.push(x);
        }
        else if(x==0){
            if(!q.empty()){
                cout << q.top() << '\n'; 
                q.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
    }

    
    return 0;
}
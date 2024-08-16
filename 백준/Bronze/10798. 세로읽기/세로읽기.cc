#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int mx=-1;

int main(){

    for(int i=0;i<5;i++){
        string str;
        cin >> str;
        v.push_back(str);

        int cnt = str.size();
        if(mx < cnt){
            mx = cnt;
        }
    }

    for(int i=0;i<mx;i++){
        for(int j=0;j<5;j++){
            if(v[j].size() >= i+1)
                cout << v[j][i];
        }
    }
    
    return 0;
}
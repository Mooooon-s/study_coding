#include <bits/stdc++.h>

using namespace std;

std::map<std::string,int> ma;

int main(){

    int n ,m;
    int cnt=0;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        ma.insert(make_pair(s,i));
    }

    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        if(ma.find(s)!=ma.end()){
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}
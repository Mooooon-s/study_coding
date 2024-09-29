#include <bits/stdc++.h>

using namespace std;

vector<int> v;
map <int,int> ma;


int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        v.push_back(m);
    }

    vector<int> uv;
    uv = v;
    sort(v.begin(),v.end());

    int idx=0;
    for(int i=0;i<v.size();i++){
        if(ma.find(v[i])==ma.end())
            ma.insert(pair<int,int>(v[i],idx++));
    }

    for(auto i = 0; i < v.size();i++){
        cout << ma.find(uv[i])->second << ' ';
    }
    
    return 0;
}
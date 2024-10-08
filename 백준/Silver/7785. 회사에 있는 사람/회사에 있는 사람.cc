#include <bits/stdc++.h>

using namespace std;

map<string,string> um;

int main(){
    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        string name,state;
        cin >> name >> state;

        auto iter = um.find(name);
        if(iter!=um.end())
            iter->second = state;
        else
            um.insert(make_pair(name,state));
    }

    // for(auto i : um){
    //     cout << i.first << ' ' << i.second << '\n';
    // }

    for(auto iter = um.end(); iter != um.begin();iter--){
        if(iter->second=="enter")
            cout << iter->first << '\n';
    }
    if(um.begin()->second == "enter")
        cout << um.begin()->first;
    
    return 0;
}
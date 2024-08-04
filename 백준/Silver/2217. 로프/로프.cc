#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

vector<int> rope;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        rope.push_back(a);
    }
    
    sort(rope.begin(),rope.end());

    int max = rope.back();
    for(int i=rope.size()-1;i>=0;i--){
        int cur = rope[i]* (n-i);
        if(max < cur){
            max = cur;
        }
    }

    cout << max;
    
    return 0;
}
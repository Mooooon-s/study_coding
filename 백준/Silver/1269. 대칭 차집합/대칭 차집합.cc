#include <bits/stdc++.h>

using namespace std;

set<int> A,B,AB,BA;

int main(void){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        A.insert(x);
    }

    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        B.insert(y);
    }

    int cntA,cntB,result;

    cntA=A.size();    
    for(auto a : A ){
        if(B.find(a)!=B.end())
            cntA--;
    }
    
    cntB=B.size();
    for(auto b : B){
        if(A.find(b)!=A.end())
            cntB--;
    }

    result = cntA+cntB;

    cout << result;


}
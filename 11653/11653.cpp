#include <iostream>
#include<vector>
using namespace std;


int main() {
    int N;
    vector<int> pn_v;
    cin>>N;
    if(N==1){
        return 0;
    }
    
    while(N!=1){
        for(int i=2;i<=N;i++){
            if(N%i==0){
                pn_v.push_back(i);
                N/=i;
                break;
            }
        }
    }
    for(auto v: pn_v){
        cout<<v<<'\n';
    }
    return 0;
}

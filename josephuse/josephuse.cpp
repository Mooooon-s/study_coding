#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
    queue<int> q;
    vector<int> v;
    int N,K;
    int a,count=1;

    cin>>N>>K;
    for(int i=1;i<=N;i++){
        q.push(i);
    }



    while(!q.empty()){
        if(count!=K){
            a=q.front();
            q.pop();
            q.push(a);
            count++;
        }else if(count==K){
            a=q.front();
            v.push_back(a);
            q.pop();
            count=1;
        }
    }

    cout<<"<";
    for(int i=0;i<v.size();i++){
        if(i<v.size()-1)
            cout<<v[i]<<", ";
        else
            cout<<v[i];
    }
    cout<<">";

    return 0;
}
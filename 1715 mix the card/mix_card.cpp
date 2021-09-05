#include<iostream>
#include<queue>

using namespace std;

int main(void){
    priority_queue<int> pq;
    int N;
    int num;
    int first,second;
    int total=0;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>num;
        pq.push(-num);
    }
    if(N==1){
        cout<<0;
        return 0;
    }
    int  t = 0;
    while(!pq.empty()){
        first=pq.top();
        pq.pop();
        second=pq.top();
        pq.pop();
        t=first+second;
        if(!pq.empty()){
            pq.push(t);
            total +=t;
        }else{
            total+=t;
        }
    }
    cout<<-total;
    return 0;
}
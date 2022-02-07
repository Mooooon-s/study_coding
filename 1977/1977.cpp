#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    int M,N;
    int sum=0,min=0;
    cin>>M;
    cin>>N;
    while(M!=N+1){
        int div=1;
        while(div!=M/2){
            if(M%div==0 && M/div==div){
                a.push_back(M);
                break;
            }
            else
                div++;
        }
        M++;
    }
    if(a.size()!=0){
        for(int i=0;i<a.size();i++){
            sum+=a.at(i);
        }
        min=a.at(0);
        cout<<sum<<endl;
        cout<<min;
    }else{
        cout<<-1;
    }
    return 0;
}
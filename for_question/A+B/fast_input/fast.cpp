#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    int a,b;
    int result;
    cin>>i;


    for(int f=0;f<i;f++){
        cin>>a>>b;
        result=a+b;
        cout<<result<<"\n";
    }

    
}
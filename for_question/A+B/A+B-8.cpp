#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int a,b;
    cin>>i;

    for(int f=0;f<i;f++){
        cin>>a>>b;
        cout<<"Case #"<<f+1<<": "<<a<<" + "<<b<<" = "<<a+b<<"\n";
    }

    return 0;
}
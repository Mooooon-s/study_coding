#include<iostream>

using namespace std;

int main(void){
    int a;
    int sum=1;
    cin>>a;
    int i;
    for(i=1;i<a;i++){
        sum+=i+1;
    }
    cout<<sum;
    return 0;
}
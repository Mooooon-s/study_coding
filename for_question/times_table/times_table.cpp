#include<iostream>

using namespace std;

int main(void){
    int a,b,result;
    int i=0;
    cin>>a;
    b=1;
    for(i=0;i<=8;i++)
    {
        result=a*b;
        cout<<a<<" * "<<b<<" = "<<result<<endl;
        b++;
    }
    return 0;
}
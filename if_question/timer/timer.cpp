#include<iostream>

using namespace std;

int main(void){
    int H,M;
    cin>>H>>M;
    int afterM=M-45;
    if(afterM<=60&&afterM>=0){
        cout<<H<<" "<<afterM;
    }
    if(M-45<0){
        H=H-1;
        if(H<0)
        {
            H=23;
        }
        M=60+(afterM);
        cout<<H<<" "<<M;
    }

    return 0;
}
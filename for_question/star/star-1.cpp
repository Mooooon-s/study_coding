#include<iostream>

using namespace std;

int main(void){
    int i;
    cin>>i;

    for(int f=0;f<i;f++){
        for(int j=0;j<f+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
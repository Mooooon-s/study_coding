#include<iostream>

using namespace std;

int main(void){
    int i;
    cin>>i;

    for(int f=0;f<i;f++){
        for(int j=f+1;j<i;j++){
            cout<<" ";
        }

        for(int k=0;k<f+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
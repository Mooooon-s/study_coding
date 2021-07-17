#include<iostream>

using namespace std;

int main(void){
    int i,x;
    cin>>i>>x;
    int *arr=new int[i];
    
    for(int f=0;f<i;f++){
        cin>>arr[f];
    }

    for(int j=0;j<i;j++){
        if(arr[j]<x){
            cout<<arr[j]<<" ";
        }
    }
    return 0;

}
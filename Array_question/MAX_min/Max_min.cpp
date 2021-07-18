#include<iostream>

using namespace std;

int Max(int *arr,int n);
int Min(int *arr,int n);

int main(void){
    int n,num;
    int max;
    int min;

    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>num;
        arr[i]=num;
    }

    max=Max(arr,n);
    min=Min(arr,n);

    cout<<min<<" "<<max;
}

int Max(int *arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i+1]!='\0' && max<arr[i+1]){
            max=arr[i+1];
        }
    }
    return max;
}

int Min(int *arr,int n){
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i+1]!='\0' && min>arr[i+1]){
            min=arr[i+1];
        }
    }
    return min;
}
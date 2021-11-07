#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string input;
    int arr[26]={0, };
    int index=0;
    int in,count=0;
    int max;
    cin>>input;
    for(int i=0;i<input.length();i++){
        in=input.at(i);
        if(in<97){
            arr[in-65]++;
        }else{
            arr[in-97]++;
        }
    }
    max=arr[0];
    for(int j=0;j<26;j++){
        if(arr[j]>max){
            max=arr[j];
            index=j;
        }
    }

    for(int i=0;i<26;i++){
        if(max==arr[i]){
            count++;
        }
    }

    if(count>1)
        cout<<"?";
    else
        cout<<(char)(index+65);

    return 0;


}
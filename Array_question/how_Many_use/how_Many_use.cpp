#include<iostream>

using namespace std;

int main(void){
    int A,B,C;
    int result;
    int length=0;
    int temp;
    int index;
    int *arr=new int[9];
    int num=1;
    
    for(int i=0;i<=9;i++){
        arr[i]=0;
    }

    cin>>A>>B>>C;
    result=A*B*C;
    temp=result;

    while(temp/10!=0){
        if(temp/10!=0){
            temp=temp/10;
            length++;
        }
    }
    
    for(int f=0;f<length;f++)
    {
        num*=10;
    }
    temp=result;
    while(temp!='\0'){
        index=temp%10;
        arr[index]+=1;
        temp/=10;
    }

    for(int i=0;i<=9;i++){
        cout<<arr[i]<<endl;
    }

}
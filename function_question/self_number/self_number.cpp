#include<iostream>
#define MAX 10001

using namespace std;

int d(int a);

int main(void){
    int *num=new int[MAX];
    fill_n(num,MAX,0);

    int count=1;
    int index_=0;
    

    while(count<MAX){
        index_=d(count);
        num[index_]=1;
        count++;
    }

    count=1;
    while(count<MAX){
        if(num[count]!=1){
            cout<<count<<endl;    
        }
        count++;
    }

}

int d(int a){
    int k=a/1000;
    int h=(a%1000)/100;
    int t=(a%100)/10;
    int f=a%10;

    return a+k+h+t+f;
}
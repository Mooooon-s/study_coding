#include<iostream>

using namespace std;

int main(void){
    int index=0;
    int input;
    int f,s;
    int Newnum;
    int sum;

    cin>>input;
    int beforenum=input;

    do{
        f=beforenum/10;//십
        s=beforenum-(f*10);//일
        sum=f+s;
        if(sum>=10){
            sum=(sum-((sum/10)*10));
        }
        Newnum=(s*10)+sum;
        beforenum=Newnum;
        index++;
    }while(input!=Newnum);
    

    cout<<index;

    return 0;
}
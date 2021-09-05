#include<iostream>
#define MAXLen 3

using namespace std;

int *MakeArray(int *a,int num);
bool Compare(int *a);

int main(void){
    int num=1;
    int innum;
    int count=0;
    int *div=new int[MAXLen];//1000이하의 수를 입력 받기 때문에 최대 3자리가 나옴(1000은 한수 X)
    cin>>innum;

    while(num<=innum){
        if(num<=99){
            count++;
        }
        else{
            if(num<1000){//1000이하의 수만 판정
                div=MakeArray(div,num);
                if(Compare(div)==true)
                    count++;
            }      
        }
        num++;
    }
    cout<<count;
}

int *MakeArray(int *a,int num){
    a[0]=(num%1000)/100;//백의 자리
    a[1]=((num%1000)%100)/10;//십의 자리
    a[2]=((num%1000)%100)%10;//1의 자리

    return a;
}

bool Compare(int *a){
    int d1,d2;
    d1=a[1]-a[0];
    d2=a[2]-a[1];

    if(d1==d2)
        return true;
    else
        return false;
}
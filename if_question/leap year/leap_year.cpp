//윤년은 4의 배수 이면서 100의 배수가 아닐때 또는 400의 배수일때
#include<iostream>

using namespace std;

int main(void){
    int input_year;
    cin>>input_year;

    if(((input_year%4==0)&&(input_year%100!=0))||input_year%400==0){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
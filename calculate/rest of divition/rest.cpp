#include<iostream>

using namespace std;

int case1(int a,int b,int c);
int case2(int a,int b,int c);
int case3(int a,int b,int c);
int case4(int a,int b,int c);

int main(void){
    int A,B,C;
    int result1,result2,result3,result4;
    cin>>A>>B>>C;
    result1=case1(A,B,C);
    result2=case2(A,B,C);
    result3=case3(A,B,C);
    result4=case4(A,B,C);

    cout<<result1<<endl;
    cout<<result2<<endl;
    cout<<result3<<endl;
    cout<<result4;
    return 0;
}

int case1(int a, int b ,int c){
    int result;
    result=(a+b)%c;
    return result;
}

int case2(int a,int b,int c){
    int result;
    result=((a%c)+(b%c))%c;
    return result;
}

int case3(int a,int b,int c){
    int result;
    result=(a*b)%c;
    return result;
}

int case4(int a,int b,int c){
    int result;
    result=((a%c)*(b%c))%c;
    return result;
}
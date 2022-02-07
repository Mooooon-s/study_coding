// 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
#include<iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int num=0;
        for(int i=1;i<=n;i++){
            num =num*10+1;
            if(num%n==0){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}

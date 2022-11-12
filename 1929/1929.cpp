/*특정 범위의 소수 구하기
에라토스테네스의 체를 이용하여 풀음
배열을 생성하고
2의 배수 3의 배수 .....n의 배수를 제거
남는 수가 소수임
*/

#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int* era;
    int a,b;
    cin>>a>>b;
    era= new int[b+1]{};
    era[0]=1;
    era[1]=1;
    
    for(int i=0;i<=b;i++){
        cout<<era[i]<<" ";
    }
    //cout<<'\n';
    for(int i=2;i<=sqrt(b);i++){
        for(int j=2;j<=b;j++){
            if(i*j<=b)
                era[i*j]=1;
        }
    }
    
    for(int i=0;i<=b;i++){
        cout<<era[i]<<" ";
    }
    //cout<<'\n';
    
    
    for(int i=a;i<=b;i++){
        if(era[i]==0){
            cout<<i<<'\n';
        }
    }
    return 0;
}
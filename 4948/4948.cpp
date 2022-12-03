#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int *era;
    int a,b;
    int cnt=0;
    
    cin>>a;
    while(a){
        cnt=0;
        b=2*a;
        era=new int[b+1];
        era[0]=1;
        era[1]=1;
        
        for(int i=2; i<b;i++){
            era[i]=0;
        }
        
        
        
        //m=ab 라면 적어도 하나는 sqrt(n)이하이다.
        for(int i=2; i<=(int)sqrt(b); i++){
            for(int j=2; i*j<=b; j++){
                era[i*j]=1;
            }
        }
        
        for(int k=a+1; k<=b; k++){
            if(era[k]==0)
                cnt++;   
        }
        
        cout<<cnt<<"\n";
        cin>>a;
    }
    return 0;
}
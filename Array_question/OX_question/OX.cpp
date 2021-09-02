#include<iostream>
#define MAX 80

using namespace std;


int main(void){
    char *inarr=new char[MAX];
    int *outarr;
    int num;
    int len=0;
    int count=0;
    int total=0;

    cin>>num;

    while(num!=0){

        cin>>inarr; //입력값

        while(inarr[len]!='\0'){
            len++;
        }

        outarr=new int[len];//변환하고 저장할 배열크기 초기화

        for(int i=len-1;i>=0;i--){
            int x=i-1;
            if(inarr[i]=='O'){
                count++;
                while(inarr[x]=='O'){
                    count++;
                    x--;
                }
            }
            outarr[i]=count;
            count=0;
        }

        for(int i=0;i<len;i++){
            total+=outarr[i];
        }
        cout<<total;
        total=0;//초기화
        num--;//입력 횟수 감소
        
        //배열 비우기
        fill_n(inarr,len,0);
        cout<<"\n";
    }
}
#include<iostream>

using namespace std;

int main(void){
    int *inarr=new int[9];
    int *outarr=new int[9];
    int *count=new int;
    int count_num=0;
    
    for(int i=0;i<10;i++){
        cin>>inarr[i];
    }

    for(int k=0;k<10;k++){
        outarr[k]=inarr[k]%42;//A와B의 나머지 값
        count[k]=0;//배열 초기화;
    }
    
    for(int i=0;i<10;i++){
    //나머지가 음수가 나올수 없으므로 같은 값이 있다면 뒤의 값를 -1로 초기화해 비교에서 제외
        if(outarr[i]!=-1){//제외된 값은 비교하지 않음
            for(int k=i+1;k<10;k++){
                if(outarr[k]!=-1&&outarr[i]==outarr[k]){//제외된 값은 비교하지 않음
                    outarr[k]=-1;//뒤의 값을 제외
                    count_num++;//같은 수일 경우
                }
            }
            count_num++;//하나도 같은 것이 없을 수도 있기 때문에 자기자신을 추가로 계산
        }
        count[i]=count_num;
        count_num=0;
    }

    for(int i=0;i<10;i++){
        if(count[i]!=0){
            count_num++;
        }
    }

    cout<<count_num;
}
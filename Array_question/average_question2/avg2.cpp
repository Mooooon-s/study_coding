#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int Case;//각 케이스의 수
    int s_num;//학생의 수
    int *score;// 점수
    float avg=0.0f;//평균
    int count=0;//평균을 넘긴 학생수
    float result;//마지막 비율 값

    cin>>Case;

    while(Case!=0){
        cin>>s_num;//학생의 수 받아오기
        score=new int[s_num];//학생의 수만큼 크기 조절
        for(int k=0;k<s_num;k++){
            cin>>score[k];//학생 수 만큼 점수 입력 받기
            avg+=score[k];//점수를 모두 더함
        }

        //케이스의 평균
        avg=avg/(float)s_num;
        //평균을 넘긴 학생수 구하기
        for(int i=0;i<s_num;i++){
            if(avg<score[i])//점수가 평균보다 클 때
                count++;//평균을 넘긴 학생수 증가
        }

        //비율계산하기
        result=((float)count/(float)s_num)*100;//비율 계산 (일부/전부*100)
        cout<<fixed;
        cout.precision(3);//소수점 3자리까지 표시하도록 고정
        cout<<round(result*1000)/1000<<"%\n";//반올림 하기
        //사용했던 것을 초기 상태로 돌리기
        fill_n(score,s_num,0);//배열 비우기
        avg=0.0f;//평균값 초기화
        count=0;//평균을 넘긴 학생수 초기화
        Case--;//남은 케이스 감소
    }
}
#include <iostream>

using namespace std;

int main(void){
    int subject=0;
    int *sub;
    int max=0;
    float *newsub;
    float avg=0.0f;

    cin>>subject;
    sub=new int[subject];
    newsub=new float[subject];

    for(int i=0;i<subject;i++){
        cin>>sub[i];
        if(max<sub[i])
            max=sub[i];
    }

    for(int i=0;i<subject;i++){
        newsub[i]=((float)sub[i]/(float)max)*100;
    }

    for(int i=0;i<subject;i++){
        avg+=newsub[i];
    }

    avg/=subject;
    cout<<avg;
}
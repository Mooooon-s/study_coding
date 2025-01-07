#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

int n;
int num[3] = {1,2,3};
int testcase;
int countCase[MAX];

void InputNum();
void Count(int a);
void Reset();

void InputNum(){
    cin >> testcase;
}

void Reset(){
    testcase=-1;
    for(int i=0;i<MAX;i++)
        countCase[i]=0;
}

void Count(int a){
    countCase[0]=1;
    for(int i=1;i<=testcase;i++){
        for(auto c : num){
            if(i-c>=0)
                countCase[i]+=countCase[i-c];
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        Reset();
        InputNum();
        Count(testcase);
        cout << countCase[testcase] << '\n';
    }

    return 0;
}
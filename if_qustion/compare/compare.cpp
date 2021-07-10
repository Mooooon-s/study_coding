#include<iostream>

using namespace std;

int main(void){
    int input_f,input_s;
    int result;
    cin>>input_f>>input_s;
    result=input_f-input_s;
    
    if(result>0){
        cout<<">";
    }else if(result==0){
        cout<<"==";
    }else{
        cout<<"<";
    }

    return 0;
    
}
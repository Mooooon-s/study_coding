#include<iostream>

using namespace std;

int main(void){
    int input_x,input_y;
    cin>>input_x>>input_y;

    if(input_x>0&&input_y>0){
        cout<<"1";
    }else if(input_x>0&&input_y<0){
        cout<<"4";
    }else if(input_x<0&&input_y<0){
        cout<<"3";
    }else if(input_x<0&&input_y>0){
        cout<<"2";
    }else{
        cout<<"원점";
    }
    return 0;
}
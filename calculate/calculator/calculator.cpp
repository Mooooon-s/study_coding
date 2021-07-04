#include<iostream>

using namespace std;

class cal{
public:
    cal();
    void getinput();
    void getoutput();
    void add();
    void minus();
    void multi();
    void div();
    void rest();
private:
    int A,B,C;
};

cal::cal(){
    A=0;
    B=0;
    C=0;
}

void cal::getinput(){
    cin>>A>>B;
}

void cal::getoutput(){
    cout<<C<<endl;
}

void cal::add(){
    if(A>=1&&B<=10000){
        C=A+B;
    }
}

void cal::minus(){
    if(A>=1&&B<=10000){
        if(A>B)
            C=A-B;
        else
            C=B-A;
    }
}

void cal::multi(){
    if(A>=1&&B<=10000){
        C=A*B;
    }
}

void cal::div(){
    if(A>=1&&B<=10000){
        C=A/B;
    }
}

void cal::rest(){
        if(A>=1&&B<=10000){
        C=A%B;
    }
}

int main(void){
    cal c;
    c.getinput();
    c.add();
    c.getoutput();
    c.minus();
    c.getoutput();
    c.multi();
    c.getoutput();
    c.div();
    c.getoutput();
    c.rest();
    c.getoutput();
    return 0;
}
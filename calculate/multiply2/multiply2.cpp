#include<iostream>

using namespace std;

struct number
{
        int a;
        int b;
        int c;
        /* data */
};

class num{
public:
    num();
    void getnum(int a);
    number returnnum();
    number cal_f(int a,number b);
    int last_cal(number c);
private:
    int f,s,t;

};

int main(void){
    num n;
    number p,q,r;
    int input_f,input_s;
    int result;

    cin>>input_f>>input_s;
    n.getnum(input_f);
    p=n.returnnum();
    n.getnum(input_s);
    q=n.returnnum();
    r=n.cal_f(input_f,q);
    result=n.last_cal(r);
    cout<<r.c<<endl<<r.b<<endl<<r.a<<endl;
    cout<<result;
}

num::num(){
    int t=0;
}

void num::getnum(int a){
    t=a/100;
    s=(a-(t*100))/10;
    f=a-((t*100)+(s*10));
}

number num::returnnum(){
    number p;
    p.a=t;
    p.b=s;
    p.c=f;

    return p;
}

number num::cal_f(int a,number b){
    number c;
    c.a=a*b.a;
    c.b=a*b.b;
    c.c=a*b.c;

    return c;
}

int num::last_cal(number c){
    int result;
    result=(c.c)+(c.b*10)+(c.a*100);
    return result;
}
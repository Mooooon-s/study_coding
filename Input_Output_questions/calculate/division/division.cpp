#include<iostream>
using namespace std;

int main(void){
    int A,B;
    double C;
    cin>>A>>B;
    if(A>0 && B<10){
        C=(double)A/(double)B;
    }
    else{
        cout<<"error"<<endl;
    }

    cout<<fixed;
    cout.precision(9);
    cout<<C;
    return 0;
}
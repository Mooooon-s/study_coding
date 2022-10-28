#include<iostream>
#include<string>
using namespace std;

class mystack{
private:
    int n;
    int top;
    int *_stack;
public:
    mystack();
    mystack(int iter){ top=-1; _stack=new int[iter]; }
public:
    void Push();
    void Pop();
    void Top();
    void Empty();
    void Size();
};

void mystack::Size(){
    cout<< top+1 <<"\n";
}

void mystack::Push(){
    cin>>n;
    top++;
    _stack[top]=n;
}

void mystack::Pop(){
    if(top==-1)
        cout<<-1<<"\n";
    else{
        cout<<_stack[top]<<"\n";
        top--;
    }
}

void mystack::Top(){
    if(top==-1)
        cout<<-1<<"\n";
    else
        cout<<_stack[top]<<"\n";
}

void mystack::Empty(){
    if(top==-1)
        cout<<1<<"\n";
    else
        cout<<0<<"\n";
}

int main(void){
    int iter;
    string in;
    cin>>iter;
    mystack s(iter);
    for(int i=0;i<iter;i++){
        cin>>in;
        if(in=="push")
            s.Push();
        else if(in=="pop")
            s.Pop();
        else if(in=="top")
            s.Top();
        else if(in=="empty")
            s.Empty();
        else if(in=="size")
            s.Size();
    }
    return 0;
}
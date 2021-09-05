#include<iostream>
using namespace std;

int *char2int(char *a,int *b,int len);
int add(int *a,int len);

int main(void){
    int len;
    cin>>len;
    char *cnum=new char[len];
    int *inum=new int[len];
    cin>>cnum;
    inum=char2int(cnum,inum,len);
    cout<<add(inum,len);
}

int *char2int(char *a,int *b,int len){
    for(int i=0;i<len;i++){
        b[i]=a[i]-48;
    }
    return b;
}

int add(int *b,int len){
    int result=0;
    for(int i=0;i<len;i++){
        result+=b[i];
    }
    return result;
}

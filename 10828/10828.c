#include<stdio.h>
#include<string.h>

struct mystack{
    int top;
    int stack[100001];
};

int main(void){
    struct mystack s;
    s.top=-1;
    int iter,n;
    char in[10];
    scanf_s("%d",&iter);
    for(int i=0;i<iter;i++){
        scanf_s("%s",&in);
        if(strcmp(in,"push")==0){
            scanf_s("%d",&n);
            s.top++;
            s.stack[s.top]=n;
        }
        else if(strcmp(in,"pop")==0){
            if(s.top==-1){
                printf_s("-1\n");
            }
            else{
                printf_s("%d", s.stack[s.top]);
                s.top--;
            }
        }
        else if(strcmp(in,"top")==0){
            if(s.top==-1){
                printf_s("-1\n");
            }
            else
                printf_s("%d",s.stack[s.top]);
        }
        else if(strcmp(in,"size")==0){
            printf_s("%d",s.top+1);
        }
        else if(strcmp(in,"empty")==0){
            if(s.top==-1){
                printf_s("1\n");
            }
            else
                printf_s("0\n");
        }
    }
    return 0;
}
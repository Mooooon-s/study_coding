#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int max;
    int num;
    int i=0;
    int *arr=new int[100];
    int index=0;
    do
    {
        cin>>num;
        arr[i]=num;
        i++;
    } while (!cin.eof());
    
    // for(int k=0;k<i;k++){
    //     cout<<"arr["<<k<<"]: "<<arr[k]<<"\n";
    // }

    max=arr[0];

    for(int f=0;f<i;f++){
        if(max<arr[f]){
            max=arr[f];
            index=f;
        }
    }

    cout<<arr[index]<<"\n"<<index+1;

    return 0;
}
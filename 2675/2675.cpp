#include<iostream>
#include<string>

int main(void){
    std::string S;
    int R,N;

    std::cin>>N;
    for(int i=0;i<N;i++){
        std::string P;
        std::cin>>R;
        std::cin>>S;
        for(int k=0;k<S.size();k++){
            for(int j=0;j<R;j++){
                P.push_back(S[k]);
            }
        }
        std::cout<<P<<std::endl;
    }

    return 0;
}
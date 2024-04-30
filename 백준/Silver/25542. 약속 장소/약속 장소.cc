#include <iostream>
#include <string>

using namespace std;

int N,L;

bool checkWord(string str1 , string str2)
{
    int cnt =0;
    for(int i=0;i<L;i++)
        {
            if(str1[i] != str2[i])
                cnt++;

            if(cnt >=2)
                return false;
        }
    return true;
}

int main() {

    cin >> N >> L;
    
    string word[N];
    
    
    for(int i=0;i<N;i++)
        {
            cin >> word[i];
        }

    for(int i=0;i<N;i++)
        {
            for(int j=0;j<L;j++)
                {
                    string placeholder = word[i];
                    for(char a = 'A'; a<='Z'; a++)
                        {
                            int flag=0;
                            placeholder[j] = a;
                            for(int k=0;k<N;k++)
                                {
                                    //cout << placeholder << " " << word[k] << endl;
                                    if(!checkWord(placeholder,word[k]))
                                    {
                                        flag =1;
                                        break;
                                    }
                                }
                            if(flag==0)
                            {
                                cout << placeholder<<endl;
                                return 0;
                            }
                        }
                }
        }

    cout << "CALL FRIEND";
    
    return 0;
}
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

//map<string,int> book;
unordered_map<string,int> book;
unordered_map<int,string> book_val;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n,m;
    cin>>n >> m;
    for(int i=0;i<n;i++)
        {
            string name;
            cin >> name;
            book.insert(make_pair(name,i+1));
            book_val.insert(make_pair(i+1,name));
        }
    
    for(int i=0;i<m;i++)
        {
            string q;
            cin >> q;
            if(book.find(q)!=book.end())
                cout << book.find(q)->second<<'\n';
            else
            {   
                cout << book_val.find(stoi(q))->second << "\n";
            }
        }
    return 0;
}
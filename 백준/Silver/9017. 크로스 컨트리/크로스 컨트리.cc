#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(void){
    int tc;
    cin >> tc;

    vector<int> teams;
    map<int,int> m;
    while(tc--){
        int num,idx;
        cin >> num;

        vector<int> teams;
        map<int,int> teamSize;
        for(int i=0;i<num;i++){
            cin >> idx;
            teams.push_back(idx);
            teamSize[idx]++;
        }

        int rank=1;
        map<int,vector<int>> teamRank;
        for(int i=0;i<num;i++){
            if(teamSize[teams[i]]==6){
                teamRank[teams[i]].push_back(rank);
            }
            else{
                continue;
            }
            rank++;
        }

        int winner = -1;
        int winscore = 123456789;
        for(const auto& tr : teamRank){
            int curscore=tr.second[0]+tr.second[1]+tr.second[2]+tr.second[3];

            if(curscore < winscore){
                winner = tr.first;
                winscore = curscore;
            }
            else if(curscore == winscore){
                if(tr.second[4] < teamRank[winner][4]){
                    winner = tr.first;
                    winscore = curscore;
                }
            }
        }

        cout << winner << '\n';
    }
}
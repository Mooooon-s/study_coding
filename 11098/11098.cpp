#include<iostream>
#include<vector>
using namespace std;

int main() {
	int Case, player;
	int price;
	string name;
	vector<vector<pair<int, string>>> team;
	vector<pair<int, string>> a;
	cin >> Case;
	for (int i = 0; i < Case; i++)
	{
		int max = 0;
		string Max_name;
		cin >> player;
		for (int j = 0; j < player; j++) {
			cin >> price;
			cin >> name;
			a.push_back(make_pair(price, name));
			
		}
		team.push_back(a);

		for (int j = 0; j < player; j++) {
			if (team.at(i).at(j).first > max) {
				max = team.at(i).at(j).first;
				Max_name = team.at(i).at(j).second;
			}
		}
		cout << Max_name << endl;
		a.clear();
	}
	return 0;
}
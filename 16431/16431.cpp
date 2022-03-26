#include<iostream>
#include<vector>
using namespace std;

class farm
{
private:
	vector<pair<int, int>> bessie, daisy, tie;
	pair<int, int> a;
	int x=0, y=0, i = 0;
public:
	void getaixs();
	void move();
	bool check(vector<pair<int, int>> a, vector<pair<int, int>> b, int i);
	void daisymove(int i);
	void bessiemovecross(int i);
	void bessiemove(int i);
	bool checkcross();
	void print();
};

void farm::getaixs() {
	cin >> x >> y;
	a = make_pair(x, y);
	bessie.push_back(a);
	cin >> x >> y;
	a = make_pair(x, y);
	daisy.push_back(a);
	cin >> x >> y;
	a = make_pair(x, y);
	tie.push_back(a);
}

void farm::move() {
	if (!check(tie, daisy, i)) {

		do {
			daisymove(i);
			//cout << daisy.size();

			i++;
		} while (!check(tie, daisy, i));
	}
	i = 0;
	if (!check(tie, bessie, i)) {

		do {
			if (checkcross()) {
				bessiemovecross(i);
			}
			else {
				bessiemove(i);
			}
			//cout << bessie.size();
			i++;
		} while (!check(tie, bessie, i));
	}

}

bool farm:: check(vector<pair<int, int>> a, vector<pair<int, int>> b, int i) {
	if (a.at(0).first == b.at(i).first && a.at(0).second == b.at(i).second)
		return true;
	else
		return false;
}

void farm::daisymove(int i) {
	int x, y;
	x = daisy.at(i).first;
	y = daisy.at(i).second;
	if (x < tie.at(0).first) {
		//cout << "move right" << endl;
		x += 1;
		daisy.push_back(make_pair(x, y));
	}
	else if (x > tie.at(0).first) {
		//cout << "move left" << endl;
		x -= 1;
		daisy.push_back(make_pair(x, y));
	}
	else if (y < tie.at(0).second) {
		//cout << "move down" << endl;
		y += 1;
		daisy.push_back(make_pair(x, y));
	}
	else if (y > tie.at(0).second) {
		//cout << "move up" << endl;
		y -= 1;
		daisy.push_back(make_pair(x, y));
	}
}

void farm::bessiemovecross(int i) {
	int x, y;
	x = bessie.at(i).first;
	y = bessie.at(i).second;
	if (x < tie.at(0).first && y>tie.at(0).second) {
		//cout << "move right up" << endl;
		x += 1;
		y -= 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (x > tie.at(0).first && y < tie.at(0).second) {
		//cout << "move left down" << endl;
		x -= 1;
		y += 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (x < tie.at(0).first && y < tie.at(0).second) {
		//cout << "move right down" << endl;
		x += 1;
		y += 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (x > tie.at(0).first && y > tie.at(0).second) {
		//cout << "move left up" << endl;
		x -= 1;
		y -= 1;
		bessie.push_back(make_pair(x, y));
	}
}

void farm::bessiemove(int i) {
	int x, y;
	x = bessie.at(i).first;
	y = bessie.at(i).second;
	if (x < tie.at(0).first) {
		//cout << "move right" << endl;
		x += 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (x > tie.at(0).first) {
		//cout << "move left" << endl;
		x -= 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (y < tie.at(0).second) {
		//cout << "move down" << endl;
		y += 1;
		bessie.push_back(make_pair(x, y));
	}
	else if (y > tie.at(0).second) {
		//cout << "move up" << endl;
		y -= 1;
		bessie.push_back(make_pair(x, y));
	}
}

bool farm::checkcross() {
	if (bessie.at(i).first == tie.at(0).first || bessie.at(i).second == tie.at(0).second) {
		return false;
	}
	else
		return true;
}

void farm::print() {
	if (bessie.size()>daisy.size()) {
		cout << "daisy"<<endl;
	}
	else if (bessie.size()<daisy.size()) {
		cout << "bessie" << endl;
	}
	else {
		cout << "tie" << endl;
	}
}

int main() {
	farm Farm;
	Farm.getaixs();
	Farm.move();
	Farm.print();
	return 0;
}
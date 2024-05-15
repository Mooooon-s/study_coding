#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string wheels[5];
int _rotate[5];

int main(void)
{
	int n;
	int num;
	for (int i = 1; i < 5; i++)
	{
		cin >> wheels[i];
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(_rotate, 0, sizeof(_rotate));
		cin >> num >> _rotate[num];
		
		//기준 왼쪽
		int now=num;
		for (int j = now - 1; j > 0; j--)
		{
			if (wheels[now][6] != wheels[j][2])
			{
				if (_rotate[now]==1)
					_rotate[j] = -1;
				else if(_rotate[now]==-1)
					_rotate[j] = 1;
			}
			else
			{
				_rotate[j] = 0;
				break;
			}

			now--;
		}

		//기준 오른쪽
		now = num;
		for (int j = now + 1; j <= 4; j++)
		{
			if (wheels[now][2] != wheels[j][6])
			{
				if (_rotate[now] == 1)
					_rotate[j] = -1;
				else if (_rotate[now]==-1)
					_rotate[j] = 1;
			}
			else
			{
				_rotate[j] = 0;
				break;
			}

			now++;
		}

		//회전
		for (int j = 0; j <= 4; j++)
		{
			if (_rotate[j] == 0)
				continue;
			else if (_rotate[j] == -1)
			{
				string temp = wheels[j].substr(1);
				wheels[j] = temp + wheels[j][0];
			}
			else if (_rotate[j] == 1)
			{
				string temp = wheels[j].substr(0, 7);
				wheels[j] = wheels[j][7]+temp;
			}
		}

	}
	int cnt = 0;
	if (wheels[1][0] == '1') cnt++;
	if (wheels[2][0] == '1') cnt += 2;
	if (wheels[3][0] == '1') cnt += 4;
	if (wheels[4][0] == '1') cnt += 8;

	cout << cnt;

	/*
	10101111
	10101111
	11010111
	*/

	return 0;
}

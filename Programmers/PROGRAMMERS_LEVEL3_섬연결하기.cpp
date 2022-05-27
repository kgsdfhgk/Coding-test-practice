#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int> &vec1, const vector<int> &vec2)
{
	return vec1[2] < vec2[2];
};

int Is_There_Cycle(vector<vector<int>> &con, int island1, int island2)
{
	int answer = 0;
	int loc1 = -1;
	int loc2 = -1;

	for (int i = 0; i < con.size(); i++)
	{
		answer = 0;

		for (const auto data : con[i])
		{
			if (data == island1)
				answer++;

			if (data == island2)
				answer++;
		}

		if (answer == 2)
			return 2;
		else if (answer == 1)
		{
			if (loc1 != -1)
			{
				loc2 = i;
				break;
			}
			else
				loc1 = i;
		}
	}

	if (loc1 == -1)
		con.push_back({ island1, island2 });
	else if (loc2 == -1)
	{
		con[loc1].push_back(island1);
		con[loc1].push_back(island2);
		sort(con[loc1].begin(), con[loc1].end());
		con[loc1].erase(unique(con[loc1].begin(), con[loc1].end()));
	}
	else
	{
		con[loc1].insert(con[loc1].end(), con[loc2].begin(), con[loc2].end());
		con.erase(con.begin() + loc2);
	}
	return 1;
};

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int idx;
	int num = 0;
	sort(costs.begin(), costs.end(), compare);
	vector<vector<int>> connected;
	connected.push_back(costs[0]);
	answer += costs[0][2];
	num++;
	connected[0].pop_back();

	for (int i = 1; i < costs.size(); i++)
	{
		idx = Is_There_Cycle(connected, costs[i][0], costs[i][1]);
		if (idx == 1)
		{
			answer += costs[i][2];
			num++;
		}
		if (num == n - 1)
			return answer;
	};

	return answer;
}

int main()
{
	int n = 5;
	vector<vector<int>> costs = { {0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7} };
	int answer;

	answer = solution(n, costs);

	cout << "answer : " << answer << endl;
	return 0;
}
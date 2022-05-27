#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

bool compare(const vector<int> &vec1, const vector<int> &vec2)
{
	return vec1[2] < vec2[2];
};

int Is_There_Cycle(vector<int> con, int island1, int island2)
{
	for (int i = 0; i < con.size(); i++)
	{
		if (con[i] == island1)
		{
			for (int j = 0; j < con.size(); j++)
			{
				if (con[j] == island2)
					return 3;
			}
			return 1;
		}

		if (con[i] == island2)
		{
			for (int j = 0; j < con.size(); j++)
			{
				if (con[j] == island1)
					return 3;
			}
			return 2;
		}
	}
	return 0;
};

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int idx;
	sort(costs.begin(), costs.end(), compare); // 가중치를 기준으로 오름차순 정렬
	vector<vector<int>> connected;
	connected.push_back(costs[0]);
	answer += costs[0][2];
	connected[0].pop_back();

	for(int i = 1; i < n; i++)
	{
		for (int j = 0; j < connected.size(); j++)
		{
			idx = Is_There_Cycle(connected[j], costs[i][0], costs[i][1]);

			if (idx == 1)
			{
				connected[j].push_back(costs[i][1]);
				answer += costs[i][2];
				break;
			}
			else if (idx == 2)
			{
				connected[j].push_back(costs[i][0]);
				answer += costs[i][2];
				break;
			}
			else if (idx == 3)
				break;
		}

		if (idx == 0)
		{
			connected.push_back({ costs[i][0], costs[i][1] });
			answer += costs[i][2];
		}
		else if (idx < 3)
		{
			// connected 에서 위의 섬 추가로 인해 서로 연결된 섬이 있는지 확인해야함
			/*
			ex)
			0 1
			2 3
			에서
			0 1 2
			2 3
			이 되었다면
			2 3을 지우고
			0 1 2 3으로 연결시켜야함
			*/
		}
	};

	

	
	return answer;
}

int main()
{
	int n = 4;
	vector<vector<int>> costs = { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8} };
	int answer;

	answer = solution(n, costs);

	cout << "answer : " << answer << endl;
	return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> vec1, vector<int> vec2)
{
	return vec1[0] < vec2[0];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int idx = 0;
	int arrange[2];
	sort(routes.begin(), routes.end(), cmp);
	arrange[0] = routes[0][0]; arrange[1] = routes[0][1];
	idx = 1;
	while (idx < routes.size())
	{			
		if (arrange[1] < routes[idx][0])
		{
			answer++;
			arrange[0] = routes[idx][0];
			arrange[1] = routes[idx][1];
			idx++;
		}
		else
		{
			if (routes[idx][1] <= arrange[1])
			{
				arrange[0] = routes[idx][0];
				arrange[1] = routes[idx][1];
				idx++;
			}
			else
			{
				arrange[0] = routes[idx][0];
				idx++;
			}
		}
	}
	if (arrange[1] >= routes[idx - 1][0])
		answer++;

	return answer;
}

int main()
{
	vector<vector<int>> routes = { {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} };
	int answer;
	answer = solution(routes);
	cout << "answer : " << answer << endl;
	return 0;
}
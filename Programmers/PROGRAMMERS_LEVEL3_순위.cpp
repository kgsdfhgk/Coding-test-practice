#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<int>> able_rank(n, vector<int>(1, 1));
	vector<bool> check(n, false);

	for (int i = 0; i < n; i++)
		able_rank[i].push_back(n);

	for (int i = 0; i < results.size(); i++) {
		if (able_rank[results[i][0] - 1][1] - 1 <= able_rank[results[i][1] - 1][1] - 1)
			able_rank[results[i][0] - 1][1]--;
		else
			able_rank[results[i][0] - 1][1] = able_rank[results[i][1] - 1][1] - 1;

		if (able_rank[results[i][1] - 1][0] + 1 >= able_rank[results[i][0] - 1][0] + 1)
			able_rank[results[i][1] - 1][0]++;
		else
			able_rank[results[i][1] - 1][0] = able_rank[results[i][0] - 1][0] + 1;
	}

	int temp;

	while (1)
	{
		temp = 0;

		for (int i = 0; i < n; i++) {
			if (check[i] == true)
				continue;
			if (able_rank[i][0] == able_rank[i][1])
			{
				check[i] = true;
				temp++;
				for (int j = 0; j < n; j++)
				{
					if (j == i)
						continue;
					if (able_rank[j][0] == able_rank[i][0])
						able_rank[j][0]++;
					if (able_rank[j][1] == able_rank[i][0])
						able_rank[j][1]--;
				}
			}
		}

		if (temp == 0)
			break;
	}

	for (int i = 0; i < n; i++)
		if (check[i] == true)
			answer++;

	return answer;
}

int main()
{
	int n = 6;
	vector<vector<int>> results = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
	int answer;

	answer = solution(n, results);
	cout << "answer : " << answer << endl;

	return 0;
}
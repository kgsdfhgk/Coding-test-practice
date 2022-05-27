#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater_equal<int>> pq;

	for (int i = 0; i < commands.size(); i++)
	{
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
			pq.push(array[j]);
		
		for (int k = 0; k < commands[i][2] - 1; k++)
			pq.pop();

		answer.push_back(pq.top());
		pq = priority_queue<int, vector<int>, greater_equal<int>>();
	}

	return answer;
}


int main()
{
	vector<int> array = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
	vector<int> answer;


	answer = solution(array, commands);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
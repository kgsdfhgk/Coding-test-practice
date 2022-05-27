#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
vector<int> solution(vector<string> operations) {
	vector<int> answer;
	return answer;
}
*/

int main()
{
	vector<string> operations = {"I 16", "I -5643", "I -12345", "D -1", "D -1", "I 123", "D -1"};
	vector<int> answer;
	int min_del = 0;
	int min;
	int temp;
	priority_queue<int, vector<int>, less_equal<int>> pq;
	
	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i][0] == 73)
			pq.push(stoi(operations[i].substr(2)));
		else if (operations[i][2] == 49)
		{
			if (pq.size() <= min_del)
				continue;

			pq.pop();
		}
		else
		{
			if (pq.size() <= ++min_del)
			{
				temp = pq.size();
				for (int j = 0; j < temp; j++)
					pq.pop();
				min_del = 0;
			}
		}
	}

	if (pq.size() == 0 || pq.size() <= min_del)
	{
		cout << "0, 0" << endl;
		return 0;
	}

	answer.push_back(pq.top());

	while (pq.size() > min_del)
	{
		min = pq.top();
		pq.pop();
	}
	
	answer.push_back(min);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
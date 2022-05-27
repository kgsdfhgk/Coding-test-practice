#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	int idx;
	vector<int>::iterator iter;

	answer += (n - lost.size());

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < lost.size(); i++)
	{
		idx = 0;
		for (iter = reserve.begin(); iter != reserve.end(); iter++)
		{
			if (lost[i] == *iter)
			{
				answer++;
				reserve.erase(iter);
				break;
			}
			if (lost[i] - 1 == *iter)
			{
				if (lost[i] == *(iter + 1))
					continue;
				reserve.erase(iter);
				answer++;
				break;
			}
			if (lost[i] + 1 == *iter)
			{
				if (lost[i + 1] == *iter)
					break;
				answer++;
				reserve.erase(iter);
				break;
			}
		}
	}
	return answer;
}

int main()
{
	int n = 9;
	vector<int> lost = { 1, 2, 3, 6, 7, 8 };
	vector<int> reserve = { 3, 4, 7 };
	int answer;

	answer = solution(n, lost, reserve);

	cout << "answer : " << answer << endl;
	return 0;
}
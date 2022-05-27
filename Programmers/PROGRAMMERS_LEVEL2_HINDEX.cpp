#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int idx, ldx = 0, rdx = citations.size() - 1, size = citations.size();

	sort(citations.begin(), citations.end());
	
	while (1)
	{
		idx = (ldx + rdx) / 2;
		answer = citations[idx];
		if (idx == ldx || idx == rdx)
		{
			if (answer == 0)
				return 0;
			if (answer == size - idx)
				return answer;
			else if (answer > size - idx)
				return size - idx;
			else
				return size - idx - 1;
		}
		if (size - idx > answer)
			ldx = idx;
		else if (size - idx < answer)
			rdx = idx;
		else
			break;	
	}

	return answer;
}

int main()
{
	vector<int> citations = { 0, 0, 0, 0, 0 };
	int answer;

	answer = solution(citations);
	cout << answer << endl;

	return 0;
}
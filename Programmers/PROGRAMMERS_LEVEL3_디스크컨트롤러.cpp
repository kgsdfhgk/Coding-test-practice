#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	return answer;
}
*/

bool cmp(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}

int main()
{
	vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };
	vector<vector<int>>::iterator iter;
	int size = jobs.size();
	int answer = 0;
	int time = 0;
	int idx = 0;
	int min;

	sort(jobs.begin(), jobs.end(), cmp);

	while (1)
	{
		min = 1001;
		for (int i = 0; i < jobs.size(); i++)
		{
			if (jobs[i][0] > time)
				break;
			if (jobs[i][1] < min)
			{
				min = jobs[i][1];
				idx = i;
			}
		}
		
		if (min == 1001)
		{
			time = jobs[0][0];
			continue;
		}

		iter = jobs.begin();
		iter += idx;
		time += jobs[idx][1];
		answer += time - jobs[idx][0];
		jobs.erase(iter);

		if (jobs.size() <= 0)
			break;
		

	}

	answer /= size;
	cout << answer << endl;

	return 0;
}
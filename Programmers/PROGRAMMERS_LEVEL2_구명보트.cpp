#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int *arr = new int[limit + 1]();

	for (int i = 0; i < people.size(); i++)
		arr[people[i]]++;

	answer += arr[limit];
	arr[limit] = 0;

	int idx_R = limit;
	int idx_L = 0;
	int idx_empty = 0;

	while (1)
	{
		idx_R--; idx_L++;

		if (idx_R <= idx_L)
			break;

		if (arr[idx_R] == 0)
			continue;

		for (int i = idx_L; i > idx_empty; i--)
		{
			if (arr[i] != 0)
			{
				answer += min(arr[i], arr[idx_R]);
				if (arr[i] < arr[idx_R])
				{
					arr[idx_R] -= arr[i];
					arr[i] = 0;
				}
				else if (arr[i] == arr[idx_R])
				{
					arr[i] = arr[idx_R] = 0;
				}
				else
				{
					arr[i] -= arr[idx_R];
					arr[idx_R] = 0;
					break;
				}
			}
		}

		if (arr[idx_R] != 0)
		{
			answer += arr[idx_R];
			arr[idx_R] = 0;
			idx_empty = idx_L;
		}
	}

	int rest = 0;

	for (int i = idx_empty + 1; i <= limit / 2; i++)
		rest += arr[i];

	answer += rest / 2;
	answer += rest % 2;

	delete[] arr;
	return answer;
}

int main()
{
	vector<int> people = {70, 80, 50};
	int limit = 100;
	int answer;

	answer = solution(people, limit);

	cout << "answer : " << answer << endl;

	return 0;
}
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> priorities = { 1, 4, 2, 6, 6, 3, 1, 5, 4, 7 };
	int location = 6;
	int answer = 0;
	int idx1 = -1;
	int idx2 = -1;

	for (int i = 9; i >= priorities[location]; i--)
	{
		for (int j = idx1 + 1; j < idx1 + 1 + priorities.size(); j++)
		{
			if (priorities[j%priorities.size()] == i)
			{
				idx2 = j%(priorities.size());
				answer++;
				if (j%priorities.size() == location)
					return answer;
				
				continue;
			}
		}
		idx1 = idx2;
	}

	return 0;
}
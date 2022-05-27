#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	for (int x = 3; x < brown; x++)
	{
		for (int y = 3; y <= x; y++)
		{
			if (yellow == (x - 2) * (y - 2) && brown == 2 * (x + y - 2))
			{
				answer.push_back(x);
				answer.push_back(y);
				return answer;
			}
		}
	}

	return answer;
}

int main()
{
	int brown = 24;
	int yellow = 24;
	vector<int> answer;
	answer = solution(brown, yellow);
	
	for (int i = 0; i < answer.size(); i++)
		cout<< answer[i]<<" ";
	cout << endl;

	return 0;
}
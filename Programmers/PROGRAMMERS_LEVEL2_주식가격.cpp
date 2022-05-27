#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
vector<int> solution(vector<int> prices) {
	vector<int> answer;
	return answer;
}
*/

int main()
{
	vector<int> prices = { 1, 2, 3, 2, 3 };
	vector<int> answer;
	int ret;

	for (int i = 0; i < prices.size(); i++)
	{
		ret = 0;
		for (int j = i + 1; j < prices.size(); j++)
		{
			ret++;
			if (prices[i] > prices[j])
				break;
		}
		answer.push_back(ret);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
int solution(vector<int> scoville, int K) {
	int answer = 0;
	return answer;
}
*/

int main()
{
	vector<int> scoville = {1, 2, 3, 9, 10, 12};
	int K = 7;
	int answer = 0;
	priority_queue<int, vector<int>, greater_equal<int>> pq;
	int temp;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	
	while (pq.top() < K)
	{
		if (pq.size() < 2)
		{
			answer = -1;
			break;
		}
		temp = pq.top();
		pq.pop();
		pq.push(temp + 2 * pq.top());
		pq.pop();
		answer++;
	}

	cout << answer << endl;
	return 0;
}
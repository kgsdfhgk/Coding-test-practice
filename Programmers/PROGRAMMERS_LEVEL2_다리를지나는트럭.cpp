#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;
	return answer;
}
*/

int main()
{
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	queue<int> trucks_on_bridge_t;
	queue<int> trucks_on_bridge_w;
	int cur_wei = 0;
	int idx = 0;
	int answer = 0;
	
	while (1)
	{
		answer++;
		if (idx < truck_weights.size() && cur_wei + truck_weights[idx] <= weight)
		{
			trucks_on_bridge_t.push(answer);
			trucks_on_bridge_w.push(truck_weights[idx]);
			cur_wei += truck_weights[idx];
			idx++;
		}

		if (answer - trucks_on_bridge_t.front() == bridge_length - 1)
		{
			cur_wei -= trucks_on_bridge_w.front();
			trucks_on_bridge_w.pop();
			trucks_on_bridge_t.pop();
			if (idx >= truck_weights.size() && trucks_on_bridge_t.empty())
				break;
		}
	}
	answer++;

	cout << answer<< endl;
	return 0;
}
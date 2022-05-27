#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
1. 첫번째 자리가 큰 경우 우선 순위 부여
2. 첫번째 자리가 같은 경우 두번째 자리 확인
3. 두번째 자리가 i보다 작은 경우 자릿수가 1인 원소에 우선 순위 부여
4. 두번째 자리가 가장 큰 원소에 우선 순위를 부여하며 같을 경우 세번째 자리를 확인
5. 세번째 자리가 가장 큰 원소에 우선 순위를 부여하나, 세번째 자리가 없는 원소와
있는 원소를 비교할 때는 세번째 자리가 i보다 크거나 같을 경우 우선 순위를 부여하고
아닐 경우 세번째 자리가 없는 원소에 우선 순위를 부여
*/
struct cmp {
	bool operator() (string a, string b)
	{
		return stoi(a + b) < stoi(b + a);
	};
};
string solution(vector<int> numbers) {
	string answer = "";
	priority_queue<string, vector<string>, cmp> pq;
	int temp;

	for (int i = 0; i < numbers.size(); i++)
		pq.push(to_string(numbers[i]));

	if (pq.top() == "0")
		return "0";
	
	temp = pq.size();

	for (int i = 0; i < temp; i++)
	{
		answer += pq.top();
		pq.pop();
	}
	
	return answer;
}

int main()
{
	vector<int> numbers = { 0, 0, 0, 0, 0};
	string answer;

	answer = solution(numbers);
	cout << answer << endl;
	return 0;
}
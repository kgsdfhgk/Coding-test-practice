#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
1. ù��° �ڸ��� ū ��� �켱 ���� �ο�
2. ù��° �ڸ��� ���� ��� �ι�° �ڸ� Ȯ��
3. �ι�° �ڸ��� i���� ���� ��� �ڸ����� 1�� ���ҿ� �켱 ���� �ο�
4. �ι�° �ڸ��� ���� ū ���ҿ� �켱 ������ �ο��ϸ� ���� ��� ����° �ڸ��� Ȯ��
5. ����° �ڸ��� ���� ū ���ҿ� �켱 ������ �ο��ϳ�, ����° �ڸ��� ���� ���ҿ�
�ִ� ���Ҹ� ���� ���� ����° �ڸ��� i���� ũ�ų� ���� ��� �켱 ������ �ο��ϰ�
�ƴ� ��� ����° �ڸ��� ���� ���ҿ� �켱 ������ �ο�
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
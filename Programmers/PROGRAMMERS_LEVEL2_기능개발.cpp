#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	int num_progress = progresses.size();
	int num_finished;
	int idx = 0;

	int *arr = new int[num_progress];

	for (int i = 0; i < num_progress; i++)
		arr[i] = 0;

	while (idx < num_progress) // 모든 기능이 배포되면 while문을 벗어남
	{
		num_finished = 0; // 배포되는 기능의 개수로 배포된다면 다시 0으로 초기화가 필요하므로

		for (int i = idx; i < num_progress; i++) // 하루가 지남을 표현. 작업의 진척도를 갱신
		{
			progresses[i] += speeds[i]; // 작업의 진척도 갱신과정

			if (progresses[i] > 99) // 만약 오늘의 작업이 끝나고 작업진도가 100이 넘었다면 준비완료
				arr[i] = 1;         // 따라서 기능의 준비상태를 확인하는 배열에 1을 저장
		}

		while (arr[idx] == 1) // 앞의 기능이 준비가 되었는지 확인, 준비 안 된 기능 전까지 모두 배포
		{
			idx++; // 기능이 준비되어 배포할 것이므로 다음 기능이 준비 되었는지 확인하기 위해 idx++해줌
			num_finished++; // 오늘 배포될 기능의 개수 +1
		}

		if (num_finished > 0) // 만약 배포될 기능이 1개 이상이라면
			answer.push_back(num_finished); // 배포될 개수를 저장
	}

	delete[] arr;
	return answer;
}

vector<int> solution2(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	priority_queue<int> pq;



	return answer;
}

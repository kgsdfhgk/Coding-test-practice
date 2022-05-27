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

	while (idx < num_progress) // ��� ����� �����Ǹ� while���� ���
	{
		num_finished = 0; // �����Ǵ� ����� ������ �����ȴٸ� �ٽ� 0���� �ʱ�ȭ�� �ʿ��ϹǷ�

		for (int i = idx; i < num_progress; i++) // �Ϸ簡 ������ ǥ��. �۾��� ��ô���� ����
		{
			progresses[i] += speeds[i]; // �۾��� ��ô�� ���Ű���

			if (progresses[i] > 99) // ���� ������ �۾��� ������ �۾������� 100�� �Ѿ��ٸ� �غ�Ϸ�
				arr[i] = 1;         // ���� ����� �غ���¸� Ȯ���ϴ� �迭�� 1�� ����
		}

		while (arr[idx] == 1) // ���� ����� �غ� �Ǿ����� Ȯ��, �غ� �� �� ��� ������ ��� ����
		{
			idx++; // ����� �غ�Ǿ� ������ ���̹Ƿ� ���� ����� �غ� �Ǿ����� Ȯ���ϱ� ���� idx++����
			num_finished++; // ���� ������ ����� ���� +1
		}

		if (num_finished > 0) // ���� ������ ����� 1�� �̻��̶��
			answer.push_back(num_finished); // ������ ������ ����
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

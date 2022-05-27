#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int score[3] = { 0, };
	int max;

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == i % 5 + 1)
			score[0]++;
		if (i % 8 == 1 && answers[i] == 1)
			score[1]++;
		else if (i % 8 == 3 && answers[i] == 3)
			score[1]++;
		else if (i % 8 == 5 && answers[i] == 4)
			score[1]++;
		else if (i % 8 == 7 && answers[i] == 5)
			score[1]++;
		else if(i % 2 == 0 && answers[i] == 2)
			score[1]++;
		if ((i % 10 == 0 || i % 10 == 1) && answers[i] == 3)
			score[2]++;
		else if ((i % 10 == 2 || i % 10 == 3) && answers[i] == 1)
			score[2]++;
		else if ((i % 10 == 4 || i % 10 == 5) && answers[i] == 2)
			score[2]++;
		else if ((i % 10 == 6 || i % 10 == 7) && answers[i] == 4)
			score[2]++;
		else if ((i % 10 == 8 || i % 10 == 9) && answers[i] == 5)
			score[2]++;
	}
	max = score[0];
	for (int i = 1; i < 3; i++)
	{
		if (max < score[i])
			max = score[i];
	}
	for (int j = 0; j < 3; j++)
	{
		if (score[j] == max)
			answer.push_back(j+1);
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main()
{
	vector<int> answers = {1, 3, 2, 4, 2};
	vector<int> answer;
	
	answer = solution(answers);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name)
{
	int str_len = name.length();
	int answer = str_len - 1;
	char ch[20];
	vector<vector<int>> A_idx_vec;
	vector<vector<int>>::iterator iter;
	vector<int> A_idx(2, 0);

	strcpy_s(ch, name.c_str());
	
	for (int i = 1; i < str_len; i++)
	{
		if (ch[i] == 'A')
		{
			if (A_idx[0] == 0)
				A_idx[0] = i;
		}
		else if (A_idx[0] != 0)
		{
			A_idx[1] = i - 1;
			A_idx_vec.push_back(A_idx);
			A_idx[0] = 0;
			A_idx[1] = 0;
		}
	}

	if (A_idx[0] != 0)
	{
		A_idx[1] = str_len - 1;
		A_idx_vec.push_back(A_idx);
	}

	for (iter = A_idx_vec.begin(); iter != A_idx_vec.end(); iter++)
	{
		if (answer > 2 * ((*iter)[0] - 1) + str_len - (*iter)[1] - 1)
			answer = 2 * ((*iter)[0] - 1) + str_len - (*iter)[1] - 1;
		if (answer > 2 * (str_len - (*iter)[1] - 1) + (*iter)[0] - 1)
			answer = 2 * (str_len - (*iter)[1] - 1) + (*iter)[0] - 1;
	}
	
	for (int i = 0; i < str_len; i++)
	{
		if (ch[i] <= 'N')
			answer += ch[i] - 'A';
		else
			answer += 'A' + 26 - ch[i];
	}


	return answer;
}

int main()
{
	string name = "AADDDDAADDDAAAA";
	int answer;

	answer = solution(name);

	cout << "answer = " << answer << endl;

	return 0;
}
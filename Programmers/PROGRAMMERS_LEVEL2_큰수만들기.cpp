#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
	int idx = 0;
	int max;
	int idx2 = 0;
	int idx3 = 0;

	while (k > 0)
	{
		idx = idx2;
		max = 0;
		for (int i = 0; i < k + 1; i++)
		{
			if (max < number[idx])
			{
				max = number[idx];
				idx3 = idx2 + i;
			}
			idx++;
		}
		
		if (idx3 > idx2)
		{
			number.erase(idx2, idx3 - idx2);
			k -= (idx3 - idx2);
		}
		idx2++;
		if (k == number.length() - idx2)
		{
			number.erase(idx2, k);
			break;
		}
	}

	return number.substr();
}

int main()
{
	string number = "243";
	int k = 2;

	string answer;

	answer = solution(number, k);

	cout << "answer : " << answer << endl;

	return 0;
}
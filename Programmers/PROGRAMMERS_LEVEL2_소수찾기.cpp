#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int IsitPrime(int n)
{
	if (n == 0 || n == 1)
		return 0;
	else if (n == 2)
		return 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
};

void nPr(int n, int r, int depth, int *check, int idx, string temp, string numbers, set<int> &nums)
{
	if (r > n)
		return ;
	if (depth == r)
	{
		nums.insert(stoi(temp));
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (check[i]) 
		{ continue; }
		check[i] = 1;
		temp += numbers[i];
		idx++;
		nPr(n, r, depth + 1, check, idx, temp, numbers, nums);
		temp.erase(idx - 1, idx);
		idx--;
		check[i] = 0;
	}
	return;
};

int solution(string numbers) {
	int answer = 0;
	int *check = new int[numbers.length()];
	for (int i = 0; i < numbers.length(); i++)
		check[i] = 0;
	string temp;
	set<int> nums;
	set<int>::iterator iter;
	for(int i = 1; i <= numbers.length(); i++)
		nPr(numbers.length(), i, 0, check, 0, temp, numbers, nums);
	delete[] check;
	
	for (iter = nums.begin(); iter != nums.end(); iter++)
		answer += IsitPrime(*iter);
	
	return answer;
}

int main()
{
	/*
	string numbers = "17";
	int answer;

	answer = solution(numbers);
	cout << answer << endl;
	*/
	string numbers = "13";
	int answer;
	answer = solution(numbers);
	cout << answer << endl;
	return 0;
}
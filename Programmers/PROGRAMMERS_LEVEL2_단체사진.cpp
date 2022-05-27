#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;



	return answer;
}
// {A, C, F, J, M, N, R, T}

int main(void)
{
	int n;
	vector<string> data;
	int answer;
	char ch[100];

	cin >> n;
	
	data.push_back("N~F=0");
	data.push_back("R~T>2");
	
	strcpy(ch, data.front().c_str());
	
	cout << ch[0] << endl;

	answer = solution(n, data);

	cout << answer << endl;

	return 0;
}
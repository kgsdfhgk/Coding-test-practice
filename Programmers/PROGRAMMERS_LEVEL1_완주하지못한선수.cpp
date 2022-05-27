#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<unsigned int, string> m;
	map<unsigned int, string>::iterator iter;
	hash<string> hash;

	for (int i = 0; i < participant.size(); i++)
		m.insert(pair<unsigned int, string>(hash(participant[i]), participant[i]));

	for (int i = 0; i < completion.size(); i++)
	{
		iter = m.begin();
		for (int j = 0; j < m.size(); j++)
		{
			if (iter->first == hash(completion[i]))
			{
				m.erase(iter);
				break;
			}
			iter++;
		}
	}
	iter = m.begin();
	answer = iter->second;
	return answer;
}

int main()
{
	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" }, completion = { "josipa", "filipa", "marina", "nikola" };
	string answer;

	answer = solution(participant, completion);

	cout << answer << endl;
	return 0;
}
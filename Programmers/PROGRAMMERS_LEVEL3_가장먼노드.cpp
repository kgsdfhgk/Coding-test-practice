#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
/*
int noname(vector<vector<int>> graph, set<int> not_visited_node, int cur_node, int target_node)
{
	int edges = 0;
	int min = 50000;
	int temp;

	if (cur_node == target_node)
		return not_visited_node.size();

	if (not_visited_node.empty())
		return 50000;

	not_visited_node.erase(not_visited_node.find(cur_node));

	for (auto i : not_visited_node)
	{
		if (graph[cur_node][i] == 1)
		{
			temp = noname(graph, not_visited_node, i, target_node);
			if (temp >= 50000)
				continue;
			if (min > not_visited_node.size() - temp + 1)
			{
				min = not_visited_node.size() - temp + 1;
			}
		}
	}

	return min;
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	set<int> connected_nodes;
	for (int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0] - 1][edge[i][1] - 1] = 1;
		graph[edge[i][1] - 1][edge[i][0] - 1] = 1;
		connected_nodes.insert(edge[i][0] - 1);
		connected_nodes.insert(edge[i][1] - 1);
	}

	multiset<int> edges_num;
	for (auto i : connected_nodes)
	{
		if (i == 0)
			continue;
		edges_num.insert(noname(graph, connected_nodes, 0, i));
	}
	multiset<int>::iterator iter;
	
	for (iter = edges_num.begin(); iter != edges_num.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	answer = edges_num.count(*(--iter));
	
	
	return answer;
}
*/

int* DFS(vector<vector<int>> graph, set<int> connected_nodes, stack<int> nodes, int count)
{
	int max[2] = { count, 0 };
	int cur_node;
	set<int> temp_set = connected_nodes;

	if (nodes.empty())
		return max;

	cur_node = nodes.top();
	nodes.pop();

	for (auto i : temp_set)
	{
		if (graph[cur_node][i] == 1)
		{
			nodes.push(i);
			connected_nodes.erase(connected_nodes.find(i));
		}
	}

};

int solution(int n, vector<vector<int>> edge)
{
	int answer = 0;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	int max_num = 0;

	set<int> connected_nodes;
	for (int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0] - 1][edge[i][1] - 1] = 1;
		graph[edge[i][1] - 1][edge[i][0] - 1] = 1;
		connected_nodes.insert(edge[i][0] - 1);
		connected_nodes.insert(edge[i][1] - 1);
	}
	stack<int> nodes;
	nodes.push(*connected_nodes.begin());
	connected_nodes.erase(connected_nodes.begin());


	return answer;
};


int main()
{
	int n = 6;
	vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
	int answer;

	answer = solution(n, edge);
	cout << "answer" << endl;
	cout << answer << endl;
	
	return 0;
}
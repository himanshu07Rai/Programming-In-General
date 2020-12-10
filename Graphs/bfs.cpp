#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int i, int j, int m, int n)
{
	return i >= 0 && i < m && j >= 0 && j < n;
}

void bfs(vector<vector<int>> &g, vector<vector<int>> &visited, int i, int j, int m, int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	// int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	// int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int r[] = {-1, 0, 0, 1};
	int c[] = {0, -1, 1, 0};
	int s = sizeof(r) / sizeof(int);
	while (!q.empty())
	{
		int old_i = q.front().first, old_j = q.front().second;
		q.pop();
		visited[old_i][old_j] = 1;
		for (int k = 0; k < s; ++k)
		{
			int newi = old_i + r[k], newj = old_j + c[k];
			if (isValid(newi, newj, m, n) && g[newi][newj] == 1 && visited[newi][newj] == 0)
			{
				visited[newi][newj] = 1;
				q.push(make_pair(newi, newj));
			}
		}
	}
}

int connectedComponents(vector<vector<int>> &g, int m, int n)
{
	int count = 0;
	vector<vector<int>> visited(m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			visited[i].push_back(0);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (g[i][j] == 1 && visited[i][j] == 0)
			{
				count++;
				bfs(g, visited, i, j, m, n);
			}
		}
	}
	return count;
}

int main()
{
	int m, n, k;
	cin >> m >> n;
	vector<vector<int>> g(m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> k;
			g[i].push_back(k);
		}
	}

	cout << connectedComponents(g, m, n) << endl;
}
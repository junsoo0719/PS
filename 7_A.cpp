#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t, n, m, a, b, c, d;
char graph[1002][1002]; //O(NM) space
bool visited[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cin >> a >> b >> c >> d;
		for (int i = 0; i < 1002; i++)
		{
			fill(graph[i], graph[i] + 1002, 'X');
			fill(dist[i], dist[i] + 1002, -1);
			fill(visited[i], visited[i] + 1002, false);
		}
		for (int j = m - 1; j >= 0; j--)
		{
			for (int i = 0; i < n; i++)
			{ //좌표 인덱싱 주의, O(NM) time
				cin >> graph[i][j];
			}
		}
		queue<pii> q;
		q.push({ a,b });
		visited[a][b] = true;
		dist[a][b] = 0;
		while (!q.empty())
		{ //O(NM) time
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (graph[nx][ny] == 'X' || visited[nx][ny] == true)
					continue;
				q.push({ nx,ny });
				visited[nx][ny] = true;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
			if (visited[c][d] == true)
				break;
		}
		cout << dist[c][d] << "\n";
	}
}

/*
 정답률
A 11/28
B 6/28
전체분반
A 43/146
B 27/146

BFS 문제
input size: O(NM) 이므로
BFS: O(NM) -> linear time
*/
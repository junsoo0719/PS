#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t;
int n, m, a, b, x, y, k;
const int INF = 1001;
int d[1002];
int dT[1002];
int res[1002];
int city[1002];

void dijkstra(const vector<pii> graph[], int dist[])
{ //const�� reference�� �����ϸ� adj�޸� �״�� ����
	fill(dist, dist + n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[1] = 0;
	pq.push({ dist[1],1 });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.Y] != cur.X)
			continue;
		for (auto nxt : graph[cur.Y])
		{
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X)
				continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({ dist[nxt.Y],nxt.Y });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<pii> adj[1002];
		vector<pii> adjT[1002];
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> x >> y;
			adj[a].push_back({ x,b });
			adj[b].push_back({ y,a });
			adjT[b].push_back({ x,a });
			adjT[a].push_back({ y,b });
		}
		cin >> k;
		dijkstra(adj, d);
		dijkstra(adjT, dT);
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> city[i];
			res[i] = d[city[i]] + dT[city[i]];
			ans = max(ans, res[i]);
		}
		cout << ans << "\n";
	}
}

/*
���ͽ�Ʈ�� k�� �ݺ��� �ʿ� X
���ͽ�Ʈ�� �� 2���� �̿��ϸ� ��
������� k�� ���ϸ� ��

���� ���� �ٲ� transpose graph�� ���� ���ͽ�Ʈ�� ����
�켱���� ť heap �̿� -> ���ͽ�Ʈ�� O(MlgN)
lazy evaluation O(MlgM)
lazy ��� X O(MlgN) (M=O(N^2))

�������⵵ O(N+M) -> O(N^2)
*/
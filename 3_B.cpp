#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t;
int n, m, a, b, x, y, k;
const int INF = 1e9;
int d[1002];
int dT[1002];

void dijkstra(vector<vector<pii>> &graph, int dist[])
{ //const에 reference로 전달하면 adj메모리 그대로 전달
	fill(dist, dist + 1002, INF);
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
		vector<vector<pii>> adj(n + 2); //메모리 크기 때문에
		vector<vector<pii>> adjT(n + 2); //동적할당 해줌
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
			int city;
			cin >> city;
			int sum = d[city] + dT[city];
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
}

/*
다익스트라 k번 반복할 필요 X
다익스트라 총 2번만 이용하면 됨
결과값만 k번 비교하면 됨

엣지 방향 바꿈 transpose graph에 대해 다익스트라 수행
우선순위 큐 heap 이용 -> 다익스트라 O(MlgN)
lazy evaluation O(MlgM)
lazy 사용 X O(MlgN) (M=O(N^2))

공간복잡도 O(N+M) -> O(N^2)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t;
int n, m, a, b, x, y, k;
vector<pii> adj[1002];
vector<pii> adjT[1002];
const int INF = 1001;
int d[1002];
int res[1002];
int city[1002];

void dijkstra(int start, vector<pii>& graph)
{
	fill(d, d + n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[start] = 0;
	pq.push({ d[start],start });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		if (d[cur.Y] != cur.X)
			continue;
		for (auto nxt : adj[cur.Y])
		{
			if (d[nxt.Y] <= d[cur.Y] + nxt.X)
				continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y],nxt.Y });
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> x >> y;
			adj[a].push_back({ x,b });
			adj[b].push_back({ y,a });
			adjT[b].push_back({ x,a });
			adjT[a].push_back({ y,b });
		}
		cin >> k;
		dijkstra(1);
		for (int i = 0; i < k; i++)
		{
			cin >> city[i];
			res[i] = d[city[i]];
		}
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			dijkstra(city[i]);
			res[i] += d[1];
			ans = max(ans, res[i]);
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
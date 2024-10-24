#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t;
bool chk[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<pii>> adj(n + 1);
		fill(chk, chk + 1001, false);
		for (int i = 1; i <= n; i++)
		{
			int w;
			cin >> w;
			adj[0].push_back({ w,i });
			adj[i].push_back({ w,0 });
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int p;
				cin >> p;
				if (j <= i) //중복 입력 받지 않는 이 조건 중요
					continue;
				adj[i].push_back({ p,j });
				adj[j].push_back({ p,i });
			}
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		chk[0] = true;
		for (auto nxt : adj[0])
			pq.push(nxt);
		int cnt = 0;
		int ans = 0;
		while (cnt < n)
		{
			auto cur = pq.top();
			pq.pop();
			if (chk[cur.Y] == true)
				continue;
			ans += cur.X;
			chk[cur.Y] = true;
			cnt++;
			for (auto nxt : adj[cur.Y])
			{
				if (!chk[nxt.Y])
					pq.push(nxt);
			}
		}
		cout << ans << "\n";
	}
}

/*
weighted complete graph
시설:노드 송전선:엣지
 - 모든 정점 포함되어야함 => n개
 - 간선 최소 연결 => n-1개
 - 사이클 발생 X
 => spanning tree 특징, 간선들의 가중치 합이 최소가 되어야 함
 => 최소신장트리 MST 문제

 발전소를 의미하는 가상의 정점 하나를 추가하고 시설을 나타내는 모든 정점들과
 해당 정점 사이에 간선을 그린다.
 각 간선의 가중치는 해당 시설의 옆에 발전소를 짓는 비용으로 설정한다

 <프림 알고리즘>
 : 시작 정점 기준 가장 작은 간선과 연결된 정점 선택하며 신장트리 확장
 - 임의의 정점 1개 선택하여 트리 집합에 삽입(발전소)
 - 트리 집합의 정점과 인접한 정점 사이의 간선 중 가장 가중치가 작은 간선 선택
 - 선택된 간선과 정점 트리 집합에 삽입
 - 모든 정점이 트리 집합에 포함되면 종료, 이 때 가중치의 합 출력

Prim(G,V)
 int ans=0;
 vector<bool> visit[0...V-1] //트리정점인지 여부를 나타내는 배열 O(V) time, O(N) space
 priority_queue<pair<int,int>, vector<pii>, greater<pii>> pq; //최소우선순위큐
 //최대 O(N^2) space
 pq.push({0,0}); //index 0을 발전소로 사용
 while !pq.empty() //최대 O(V^2)번 수행
	(now_weight, now_index) = pq.top();
	pq.pop(); //T(RemoveMin) = O(log V^2) = O(log V)
	if visit[now_index] == true
		continue;
	ans=ans+now_weight;
	visit[now_index]=true;
	for next_index=0 to V-1 //O(n)번 반복
		if visit[next_index] != true
			pq.push({G[now_index][next_index], next_index}); //pq에 넣음
			// T(insert) = log(V^2) = O(log V)
 return ans; //O(V + V^2T(RemoveMin) + V^2T(insert)) = O(V^2log V) time
 //O(N^2) space

Main
 vector<vector<int>> graph[N][N] //O(N^2) space
 for i=1 to N
	graph[0][i]=graph[i][0]=cost //발전소를 건설하는 비용
 for i=1 to N
	for j=1 to N
		read graph[i][j] //송전선을 매설하는 비용 입력
 print Prim(graph, N+1)
*/
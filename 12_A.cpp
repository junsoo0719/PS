#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k, m;
		cin >> n >> k >> m;
		vector<vector<int>> graph(k + 1); //그래프 인접 리스트
		vector<int> indeg(k + 1); //각 노드 진입 차수
		vector<int> require(k + 1); //각 과목 최소 학기 수
		for (int i = 0; i < m; i++) //선수 조건 입력
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b); //a->b 간선
			indeg[b]++; //b의 진입 차수
		}

		queue<int> sorting_q; //진입 차수 0인 노드 처리
		for (int i = 1; i <= k; i++)
		{
			if (indeg[i] == 0)
			{
				sorting_q.push(i); //진입 차수 0인 노드 큐 삽입
				require[i] = 1; //선수 과목 X
			}
		}
		while (!sorting_q.empty()) //위상 정렬
		{
			int cur = sorting_q.front();
			sorting_q.pop();
			for (int next : graph[cur])
			{ //다음 노드 최소 학기: 현재 노드 학기+1
				require[next] = max(require[next], require[cur] + 1);
				if (--indeg[next] == 0) //간선 제거, 진입 차수 감소
					sorting_q.push(next); //진입 차수 0 되면 큐 삽입
			}
		}

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;

			if (require[query] <= n)
				cout << "True\n";
			else
				cout << "False\n";
		}
	}
}

/*
 정답률
A 3/28
B 1/28
전체분반
A 18/135
B 3/135

선수과목 - 방향성 O, 사이클 X
선수조건 -> 위상 정렬
DAG(directed acyclic graph)

한 과목을 이수하기 위해 필요한 최소 학기 구는 선수과목이 없다면 1,
선수 과목이 존재한다면 선수과목 중 필요한 최소 학기 수가 최대인 것 +1
DAG 상에서 과목 간의 선후관계를 고려하여 순서를 결정하는
위상 정렬(topological sort)로 해결할 수 있음

<Basic Idea>
1. 진입차수(indegree)가 0인 노드들로부터 순방향으로 진행하는 방식
2. 진출차수(outdegree)가 0인 노드들로부터 역방향으로 진행하는 방식
=> 이 문제는 1번 방식이 적합

1. 진입차수(indegree)가 0인 노드를 큐에 넣는다.
2. 큐가 빌 때까지 다음의 과정을 반복한다.
	2-1. 큐에서 노드 하나를 꺼낸다
	2-2. 해당 노드와 해당 노드에 부속된 간선들을 삭제한다
	2-3. 삭제 이후, 새로 진입차수가 0이 된 노드를 큐에 넣는다
(진입차수: 외부 노드에서 한 노드로 들어오는 간선의 수)

- 주어진 과목들의 정보로부터 graph를 형성한다
- 모든 노드의 진입차수를 먼저 계산한다
- 진입차수가 0인 노드들은 최소 학기가 1이다
- 해당 노드들을 큐에 넣는다
- 큐에서 노드 하나를 꺼낸다
- 해당 노드와 부속된 간선들을 삭제한다
- 간선을 삭제하면서 인접 정점의 최소 학기를 갱신한다
- 삭제 이후, 새로 진입 차수가 0이 된 노드를 큐에 넣는다

Global variables
vector<int> graph[1..K] //인접 리스트 방식으로 표현된 그래프 O(K+M)
int indegree[1..K] //진입 차수 O(K)
int required_semester[1..K] //과목 수강에 필요한 최소 학기 수 O(K)
//전체: O(K+M) space

CalculateRequiredSemester()
	queue<int> sorting_queue
	for i=1 to K //O(K) time
		if indegree[i]==0
			sorting_queue.push(i)
			required_semester=1
	while !sorting_queue.empty()
		int now=sorting_queue.front()
		sorting_queue.pop()
		for next in graph[now]
			required_semester[next]=max(required_semester[now]+1,
									required_semester[next])
			if --indegree[next]==0
				sorting_queue(next)
	 //전체: O(K+M) time (모든 노드와 간선을 1번씩 순회)

main()
	for i=1 to M //O(M) time
		graph[a].push_back(b)
		indegree[b]++
	CalculateRequiredSemester() //O(K+M) time
	for i=1 to Q //O(Q) time
	//전체: O(K+M+Q) time
*/
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t, n;
int cost[1002];
int board[1002][1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for (int i = 1; i <= n; i++)
		{
			cin >> cost[i];
			pq.push({ cost[i],i });
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> board[i][j];
			}
		}

		while (!pq.empty())
		{
			pii cur = pq.top();
			pq.pop();
			if (cur.X != cost[cur.Y]) continue;
			for (int i = 1; i <= n; i++)
			{
				if (board[i][cur.Y] + cur.X <= cost[i])
				{
					cost[i] = board[i][cur.Y] + cur.X;
					pq.push({ cost[i],i });
				}
			}
		}

		int total = 0;
		for (int i = 1; i <= n; i++)
		{
			total += cost[i];
		}
		cout << total << "\n";

		fill(cost, cost + n, 0);
		for (int i = 1; i <= n; i++)
		{
			fill(board[i], board[i] + n, 0);
		}
	}
}

/*
weighted complete graph
�ü�:��� ������:����
 - ��� ���� ���ԵǾ���� => n��
 - ���� �ּ� ���� => n-1��
 - ����Ŭ �߻� X
 => spanning tree Ư¡, �������� ����ġ ���� �ּҰ� �Ǿ�� ��
 => �ּҽ���Ʈ�� MST ����

 �����Ҹ� �ǹ��ϴ� ������ ���� �ϳ��� �߰��ϰ� �ü��� ��Ÿ���� ��� �������
 �ش� ���� ���̿� ������ �׸���.
 �� ������ ����ġ�� �ش� �ü��� ���� �����Ҹ� ���� ������� �����Ѵ�

 <���� �˰���>
 : ���� ���� ���� ���� ���� ������ ����� ���� �����ϸ� ����Ʈ�� Ȯ��
 - ������ ���� 1�� �����Ͽ� Ʈ�� ���տ� ����(������)
 - Ʈ�� ������ ������ ������ ���� ������ ���� �� ���� ����ġ�� ���� ���� ����
 - ���õ� ������ ���� Ʈ�� ���տ� ����
 - ��� ������ Ʈ�� ���տ� ���ԵǸ� ����, �� �� ����ġ�� �� ���

Prim(G,V)
 int ans=0;
 vector<bool> visit[0...V-1] //Ʈ���������� ���θ� ��Ÿ���� �迭 O(V) time, O(N) space
 priority_queue<pair<int,int>, vector<pii>, greater<pii>> pq; //�ּҿ켱����ť
 //�ִ� O(N^2) space
 pq.push({0,0}); //index 0�� �����ҷ� ���
 while !pq.empty() //�ִ� O(V^2)�� ����
	(now_weight, now_index) = pq.top();
	pq.pop(); //T(RemoveMin) = O(log V^2) = O(log V)
	if visit[now_index] == true
		continue;
	ans=ans+now_weight;
	visit[now_index]=true;
	for next_index=0 to V-1 //O(n)�� �ݺ�
		if visit[next_index] != true
			pq.push({G[now_index][next_index], next_index}); //pq�� ����
			// T(insert) = log(V^2) = O(log V)
 return ans; //O(V + V^2T(RemoveMin) + V^2T(insert)) = O(V^2log V) time
 //O(N^2) space

Main
 vector<vector<int>> graph[N][N] //O(N^2) space
 for i=1 to N
	graph[0][i]=graph[i][0]=cost //�����Ҹ� �Ǽ��ϴ� ���
 for i=1 to N
	for j=1 to N
		read graph[i][j] //�������� �ż��ϴ� ��� �Է�
 print Prim(graph, N+1)
*/
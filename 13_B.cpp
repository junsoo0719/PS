#include <iostream>
#include <vector>
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
		int n, m;
		cin >> n >> m;

		vector<int>	t(n + 1);
		vector<int> h(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++)
			cin >> t[i];
		for (int i = 1; i <= n; i++)
			cin >> h[i];

		for (int i = 1; i <= n; i++)
		{ //dp[0][j]은 어떤 어트랙션도 이용할 수 없기 때문에 위에서 0으로 초기화
			for (int j = 1; j <= m; j++)
			{
				if (j < t[i]) //현재 어트랙션 이용할 수 없는 경우
					dp[i][j] = dp[i - 1][j];
				else //선택하지 않는 경우, 선택하는 경우 중 최댓값
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + h[i]);
			}
		}
		cout << dp[n][m] << "\n"; //최대 만족도
	}
}

/*
0/1 knapsack problem

각각 어트랙션은 최대 1번까지 이용할 수 있고, 그 순서는 상관 없기
때문에 최대 2^N개의 조합 존재

Solve(1,N,M)을 [1..M]의 어트랙션에 대해 M의 시간 동안 최대
만족도를 얻는 조합
조합을 각각 어트랙션을 이용했는지 여부에 따라
(x1, x2, ..., xn)
xn = 0이면 (n번째 어트랙션 이용 X)
조합(x1, x2, ..., xn-1)은 Solve(1,N-1,M)의 최적해
xn = 1이면 (n번째 어트랙션 이용 O)
조합(x1, x2, ..., xn-1)은 Solve(1,N-1,M-tn)의 최적해

DP[n,m]을 Solve(1,n,m)에서 얻을 수 있는 최대 만족도
DP[n,m] = max(DP[n-1,m], DP[n-1,m-tn] + hn)
xn=0/1인 경우 얻을 수 있는 최대 만족도
항상 이전 행의 결과만 사용

DP[0,j]은 어떤 어트랙션도 이용할 수 없기 때문에 0으로 초기화
(행: 어트랙션 번호, 열: 시간)
DP[i,j] = max(DP[i-1,j], DP[i-1,j-ti] + hi)
j-ti가 0보다 작은 경우, i번째 어트랙션을 이용할 수 없기 때문에
DP[i,j]=DP[i-1,j]

DP[i,j] = DP[i-1,j] (if j - ti < 0)
		= max(DP[i-1,j], DP[i-1,j-ti] + hi) (else)

어트랙션 1 2 3 4
이용시간 6 4 3 5
만족도 13 8 6 7

i/j 0	1	2	3	4	5	6	7
0   0	0	0	0	0	0	0	0
1   0	0	0	0	0	0	13	13
2	0	0	0	0	8	8	13	13
3	0	0	0	6	8	8	13	14
4	0	0	0	6	8	8	13	14
DP[n,m] 출력

int dp[0..n][0..m] //O(nm) space
int t[0..n]
int h[0..n]

for j=0 to m
	dp[0][j]=0
for i=0 to n
	for j=0 to m
		if j-ti < 0
			dp[i][j] = dp[i-1,j]
		else
			dp[i][j] = max(dp[i-1,j], dp[i-1,j-ti] + hi)
print dp[n][m]
*/
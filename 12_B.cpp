#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k; //사탕 수, 친구 수, 한 명의 최대 사탕 수
		cin >> n >> m >> k;

		vector<vector<int>> dp(m + 1, vector<int>(n + 1)); //dp[i][j]: i명이 j개 사탕 받는 경우의 수, 0 초기화	
		dp[0][0] = 1; //0명에게 0개의 사탕을 나눠준 경우는 항상 1
	
		for (int i = 1; i <= m; i++) //i명 (0명에게 j개 사탕 나눠준 경우는 성립 X, 위에서 0으로 초기화)
		{
			for (int j = 0; j <= n; j++) //j개 사탕
			{
				for (int x = 0; x <= min(k, j); x++) //x: i번재 친구가 받은 사탕 수
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
				}
			}
		}

		int equal = min(k, n / m) + 1; //모든 친구가 사탕 동일하게 받는 경우, 0개씩 받은 경우 +1
		int total = 0;
		for (int j = 0; j <= n; j++) //m명에게 n개 이하 나눠준 경우의 수
			total = (total + dp[m][j]) % MOD;
		cout << total - equal << "\n";
	}
}

/*
<Basic Idea> (N 사탕 수, M: 친구 수)
- 우선 모든 친구가 같은 양의 사탕을 받는 상황도 포함해서 생각
- M명의 친구에게 j개의 사탕을 남김없이 나눠주되, 한 명에게는 K개까지
나눠줄 수 있는 경우의 수를 S(M,j,K)
- 사탕을 전부 다 나눠줄 필요가 없으므로, j=0~N까지 S(M,j,K)합을 구함
- S(M,j,K)를 구하는 과정
- 한 명에게는 K개까지 나눠줄 수 있으므로, t번째 친구가 받은 사탕의
양을 A[t]라 하면 0<=A[t]<=K 성립
- M번째 친구부터 고려하고 나머지 친구들을 차례대로 고려
전체 j개의 사탕을 M명의 친구에게 나눠줬을 때. M번째 친구가 A[M]개를
받았다면, 나머지 M-1명의 친구들은 j-A[M]개의 사탕을 나눠서 받음
(0<=A[M]<=K)
- A[M]=i로 치환, i=0~K
점화식: S(M,j,K) = i=0~K까지 S(M-1,j-1,K)합

DP[i][j] = S(i,j,K): i명에게 j개의 사탕을 남김없이 나눠준 경우의 수
DP[0][0]: 0명에게 0개의 사탕을 나눠준 경우의 수로 항상 1
j>0일 때 0명에게 j개를 준 경우는 성립할 수 없으므로 DP[0][j]=0
(i는 친구의 수, j는 사탕의 수)

DP[0][j] = 1 (j=0)			(0<=j<=N)
		   0 (otherwise)

DP[i][j] = k=0 부터 min(K,j)까지 DP[i-1][j-k] 합
(i번째 친구가 받는 사탕의 개수 k)
ex) N=5, M=4, K=2일 때
- DP[3][3]일 때 3번 친구가 0개를 받을 경우:
	2번 친구까지 3개를 받는 경우의 수 DP[2][3]
- 3번 친구가 1개를 받을 경우:
	2번 친구까지 2개를 받는 경우의 수 DP[2][2]
- 3번 친구가 2개를 받을 경우:
	2번 친구까지 1개를 받는 경우의 수 DP[2][1]

모든 친구가 같은 양의 사탕을 받는 경우의 수는
각각 1개 받았을 때 총 M개,
...
각각 x개 받았을 때 총 xM개이므로
x<=K && xM<=N인 최대 xmax를 구함 -> xmax = min(K,N/M)
따라서 (j=0~N까지 S(M,j,K)합) - (xmax+1) = 마지막 행합 - (xmax + 1)
+1 하는 것은 모든 친구가 0개씩 받은 경우 1을 추가

for i=1 to M
	for j=1 to N
		 for k=0 to K
			if j-k < 0
				continue
			DP[i][j] = (DP[i][j] + DP[i-1][j-k]) mod
int x=min(K,N/M) //모든 친구들이 같은 사탕을 받는 경우
int ans=0
for i=0 to N //M명에게 N개 이하의 사탕을 나눠주는 경우
	ans=(ans+DP[M][i]) mod
print ans - x - 1
*/
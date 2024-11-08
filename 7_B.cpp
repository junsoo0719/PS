#include <iostream>
using namespace std;

int t, n, m;
int load[501][501];
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < 501; i++)
		{
			fill(load[i], load[i] + 501, 0);
			fill(dp[i], dp[i] + 501, 0);
		}
		int total_count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> load[i][j];
				if (load[i][j] == 1)
					total_count++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{ // dp[0][0], dp[0][1], dp[1][0]은 다 0으로 초기화되어있음
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + load[i][j];
			}
		}
		cout << total_count - dp[n][m] << "\n";
	}
}

/*
Basic Idea
현재 위치까지 이동하는 과정에서 왼쪽, 위쪽 구역에서 치울 수 있는 물건의
최대 개수를 저장하고 현재 위치에서 물건의 존재 여부를 반영하여
현재 위치까지 치울 수 있는 물건의 최대 개수 계산

load[i][j]: 물건의 존재 여부 //O(NM) space
dp[i][j]: 치울 수 있는 물건의 최대 개수 //O(NM) space
total_count: 전체 물건 개수
dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + load[i][j]
dp[i][j] = 0 (i=0 or j=0)

(1,1)부터 행 우선으로 순회하면서, 직전 위치까지 확인된 정보를 이용하여
치울 수 있는 물건의 최대 개수를 갱신

for i=1 to N
	for j=1 to M //O(NM) time
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + load[i][j]

print total_count - dp[n][m]

input size: O(NM) 이므로
O(NM) -> linear time
*/
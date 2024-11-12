#include <iostream>
using namespace std;

int t;
int dp[3001][3001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;

		dp[0][0] = 0;
		for (int i = 1; i <= s1.size(); i++)
			dp[i][0] = i;
		for (int j = 1; j <= s2.size(); j++)
			dp[0][j] = j;

		for (int i = 1; i <= s1.size(); i++)
		{
			for (int j = 1; j <= s2.size(); j++)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]),
									dp[i - 1][j - 1]) + 1;
				}
			}
		}
		cout << dp[s1.size()][s2.size()] << "\n";
	}
}
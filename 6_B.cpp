#include <iostream>
using namespace std;

int t;
const int MOD = 1'000'000'007;
long long cnt[10'000'001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;
	for (int i = 4; i < 10'000'001; i++)
	{
		cnt[i] = (cnt[i - 1] + cnt[i - 2] + cnt[i - 3]) % MOD;
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << cnt[n] << "\n";
	}
}
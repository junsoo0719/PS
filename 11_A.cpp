#include <iostream>
#include <vector>
using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v;
		for (int i = 1; i <= n; i++)
			v.push_back(i);
		int cur_idx = 0;
		while (n > 0)
		{
			cur_idx = (cur_idx + k) % n;
			auto cur = v.begin() + cur_idx;
			cout << *cur << " ";
			v.erase(cur);
			n--;
		}
		cout << "\n";
	}
}
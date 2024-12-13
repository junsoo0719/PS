#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;
int t;
int harvest_time[1'000'000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n, cur_time;
		cin >> n >> cur_time;
		priority_queue<pii> harvest_available;
		priority_queue<pii, vector<pii>, greater<pii>> nonavailable;
		for (int i = 0; i < n; i++)
		{
			cin >> harvest_time[i];
		}
		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			if (harvest_time[i] <= cur_time)
				harvest_available.push({ p,harvest_time[i]});
			else
				nonavailable.push({ harvest_time[i],p });
		}

		long long total = 0; // long long 타입 중요
		while (!harvest_available.empty() || !nonavailable.empty())
		{
			if (!harvest_available.empty())
			{
				auto harvest_crop = harvest_available.top();
				harvest_available.pop();
				total += (long long)(cur_time - harvest_crop.Y) * harvest_crop.X;
				cur_time++;
			}
			else
				cur_time = nonavailable.top().X;

			while (!nonavailable.empty() && nonavailable.top().X <= cur_time)
			{
				auto available_crop = nonavailable.top();
				nonavailable.pop();
				harvest_available.push({ available_crop.Y, available_crop.X });
			}
		}
		cout << total << "\n";

		/*
		int cnt = 0;
		while (cnt < n)
		{
			if (!harvest_available.empty())
			{
				auto harvest_crop = harvest_available.top();
				harvest_available.pop();
				total += (long long)(cur_time - harvest_crop.Y) * harvest_crop.X;
				cnt++;
			}  //long long 타입 중요
			cur_time++;
			while (!nonavailable.empty() && nonavailable.top().X <= cur_time)
			{
				harvest_available.push({ nonavailable.top().Y, nonavailable.top().X });
				nonavailable.pop();
			}
		}
		cout << total << "\n";
		*/
	}
}

/*
pq에 최대 N번 삽입 O(N) space
*/
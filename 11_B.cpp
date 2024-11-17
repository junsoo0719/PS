#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;
int t;
int get_time[1'000'000];

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
		priority_queue<pii> pq;
		priority_queue<pii, vector<pii>, greater<pii>> min_pq;
		for (int i = 0; i < n; i++)
		{
			cin >> get_time[i];
		}
		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			if (get_time[i] <= cur_time)
				pq.push({ p,get_time[i]});
			else
				min_pq.push({ get_time[i],p });
		}

		int total = 0;
		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			total += (cur_time - cur.Y) * cur.X;
			cur_time++;
			while (!min_pq.empty() && min_pq.top().X <= cur_time)
			{
				pq.push({ min_pq.top().Y, min_pq.top().X });
				min_pq.pop();
			}
		}
		cout << total << "\n";
	}
}
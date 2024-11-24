#include <iostream>
#include <queue>
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
		
		queue<int> q; // O(N) space
		for (int i = 1; i <= n; i++)
			q.push(i);

		while (!q.empty())
		{ // O(N) time
			for (int i = 0; i < k; i++)
			{
				int cur = q.front();
				q.pop();
				q.push(cur);
			} // O(K) time
			cout << q.front() << " ";
			q.pop();
		} // O(N * K) time
		cout << "\n";

		/*
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
		*/
	}
}

/*
 정답률
A 19/28
B 1/28
전체분반
A 91/135
B 9/135

vector의 iterator를 사용해서 erase하며 풀었지만,
queue 자료구조를 사용하는 것이 훨씬 간단
*/
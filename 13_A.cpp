#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int A[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> A[i][j];
			} //초기화 안 해도 덮어써서 괜찮음
		}

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;
			bool found = false;
			for (int j = 0; j < n; j++)
			{
				if (A[j][0] <= query && query <= A[j][m - 1])
				{
					if (binary_search(A[j], A[j] + m, query))
					{
						found = true;
						break;
					}
				}
			}
			if(found)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";

		/* 1차원 배열로도 가능
		vector<int> A_flat(n * m); //O(NM) space
		for (int i = 0; i < n * m; i++)
		{
			cin >> A_flat[i];
		}

		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;
			if (binary_search(A_flat.begin(), A_flat.end(), query))
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
		*/
	} //O(Q log NM) time
}

/*
 정답률
A 21/28
B 3/28
전체분반
A 97/135
B 17/135
*/
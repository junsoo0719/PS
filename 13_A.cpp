#include <iostream>
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
			}
		}

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;
			int row = -1;
			for (int j = 0; j < n; j++)
			{
				if (query <= A[j][m - 1])
				{
					row = j;
					break;
				}
			}
			if (row >= 0)
			{
				bool find = false;
				for (int j = 0; j < m; j++)
				{
					if (query == A[row][j])
					{
						find = true;
						break;
					}
				}
				if (find == true)
				{
					cout << "1 ";
					continue;
				}
			}
			cout << "0 ";
		}
		cout << "\n";
	}
}
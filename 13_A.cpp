#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> A(n * m); //O(NM) space n*m 1차원 배열
		for (int i = 0; i < n * m; i++)
			cin >> A[i];

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;
			if (binary_search(A.begin(), A.end(), query)) //존재 여부
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
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
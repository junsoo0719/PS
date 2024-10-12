#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MOD = 1'000'000'007;

int t;

vector<vector<ll>> matrixMult(vector<vector<ll>>& a, vector<vector<ll>>& b)
{ //O(1)
	vector<vector<ll>> ret(2, vector<ll>(2));
	ret[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	ret[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	ret[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	ret[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	return ret;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> m, ll n)
{ //T(N) = T(N/2) + O(1) = O(log N) 
	vector<vector<ll>> res = { {1,0},{0,1} };
	while (n > 0)
	{ //O(log N)번 반복 -> 재귀 호출 O(log N) space
		if (n % 2 == 1)
		{
			res = matrixMult(m, res);
		}
		m = matrixMult(m, m);
		n /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		vector<vector<ll>> m(2, vector<ll>(2));
		ll n;
		cin >> m[0][0] >> m[0][1];
		cin >> m[1][0] >> m[1][1];
		cin >> n; 
		
		vector<vector<ll>> res = matrixPow(m, n); 
		cout << res[0][0] << " " << res[0][1] << "\n";
		cout << res[1][0] << " " << res[1][1] << "\n";
	} //O(log N) time, O(log N) space
}

/*
N이 홀수일 때: A * A^(N-1)/2 * A^(N-1)/2
범위 때문에 long long 혹은 unsigned long long 사용

M^N = M^N/2 * M^N/2 (N짝수)
	= M * M^N-1 (N홀수)
항등행렬이 나올 때까지 분할 후 계산
*/
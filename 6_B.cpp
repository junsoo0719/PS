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
	{ //O(N) time, O(N) space
		cnt[i] = (cnt[i - 1] + cnt[i - 2] + cnt[i - 3]) % MOD;
	}
	while (t--)
	{
		int n;
		cin >> n;
		cout << cnt[n] << "\n";
	}
}

/*
점화식 FN = FN-1 + FN-2 + FN-3
dp의 핵심은 중복되는 subproblem을 한번만 계산하고 다음에 다시 이용
overlapping subproblem

최대 크기: MOD * 3인데 int범위를 넘지 않으므로 long long 대신 int사용 좋음
int 양수 최대 범위 2^31-1
MOD*3은 2^31-1보다는 크지만 2^32보다는 작으므로
unsigned int 사용할 수 있음

unsigned int f[4] = {0,1,2,4}; //이렇게 사용하면 O(1) space로 가능
unsigned int n;
for i=4~N
	f[i % 4]=(f[(i-1)% 4]+f[(i-2)% 4]+f[(i-3)% 4]) % MOD;
print f[N%4];
*/
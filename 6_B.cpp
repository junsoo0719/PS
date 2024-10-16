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
��ȭ�� FN = FN-1 + FN-2 + FN-3
dp�� �ٽ��� �ߺ��Ǵ� subproblem�� �ѹ��� ����ϰ� ������ �ٽ� �̿�
overlapping subproblem

�ִ� ũ��: MOD * 3�ε� int������ ���� �����Ƿ� long long ��� int��� ����
int ��� �ִ� ���� 2^31-1
MOD*3�� 2^31-1���ٴ� ũ���� 2^32���ٴ� �����Ƿ�
unsigned int ����� �� ����

unsigned int f[4] = {0,1,2,4}; //�̷��� ����ϸ� O(1) space�� ����
unsigned int n;
for i=4~N
	f[i % 4]=(f[(i-1)% 4]+f[(i-2)% 4]+f[(i-3)% 4]) % MOD;
print f[N%4];
*/
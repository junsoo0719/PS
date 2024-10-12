#include <iostream>
#include <algorithm>
using namespace std;

int t;
int clk[11];
int arr[8] = { 2,3,5,7,11,13,17,19 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long ans = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> clk[i];
			ans *= clk[i];
		}
		int cidx = 0;
		int aidx = 0;
		long long cur = 0;
		while (aidx < 8)
		{
			if (ans % arr[aidx] != 0)
			{
				aidx++;
				continue;
			}
			cur = ans / arr[aidx];
			while (cidx < n)
			{
				if (cur % clk[cidx] != 0)
					break;
				cidx++;
			}
			if (cidx == n)
			{
				ans = cur;
				cidx = 0;
				continue;
			}
			aidx++;
			cidx = 0;
		}
		cout << ans << "\n";

		/*���� Ǯ��
		int N; //�ð� ��
		int clk[10]; //�� �ð� 1���� �ð� O(N) space
		for i 0~N-1 //O(N)
			read clk[i]
		ans=clk[0]
		for i 1~N-1 //O(N)
			gcd=GCD(ans,clk[i]) //O(time(GCD))
			ans=ans*clk[i]/gcd
		//��ü O(N * time(GCD)) = O(N * log(max(clk[i])))
		*/
	}
}

/*
<Basic Idea>
�ּҰ����(Least Common Multiple)
�� ���� ���� a,b
�ִ�����(Greatest Common Divisor)

12,30�� �ִ�����
12=2*2*3
30=2*3*5
gcd(12,30)=2*3=6
lcm(12,30)=2*2*3*5=60 (�ߺ��� �κ� ����(�� ����))

��Ŭ���� ȣ����
�� ���� ���� a,b(a>b) a=bq+r(0<=r<b) (�� r=a mod b)
a,b�� �ִ� �����= b,r�� �ִ�����

�ּҰ���� lcm(a,b)=a*b/gcd(a,b)

3�� �̻��� ���� ���� �ݺ������� ���
1,2,3�� ��
1) gcd(1,2)=1
	lcm(1,2)=1*2/gcd(1,2)=2 �� ���� �Ʒ� gcd�� ù input���� ��
2) gcd(2,3)=1
	lcm(2,3)=2*3/gcd(2,3)=6
*/

/*
��Ŭ���� ȣ����
����Լ�
gcd(a, b) //�ִ�����
{
	r=a mod b;
	if r == 0 then
	gcd(b, a % b);
}
lcm(a, b) //�ּҰ����
{
	a * b / gcd(a, b);
}
*/
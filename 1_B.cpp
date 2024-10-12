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

		/*수업 풀이
		int N; //시계 수
		int clk[10]; //각 시계 1바퀴 시간 O(N) space
		for i 0~N-1 //O(N)
			read clk[i]
		ans=clk[0]
		for i 1~N-1 //O(N)
			gcd=GCD(ans,clk[i]) //O(time(GCD))
			ans=ans*clk[i]/gcd
		//전체 O(N * time(GCD)) = O(N * log(max(clk[i])))
		*/
	}
}

/*
<Basic Idea>
최소공배수(Least Common Multiple)
두 양의 정수 a,b
최대공약수(Greatest Common Divisor)

12,30의 최대공약수
12=2*2*3
30=2*3*5
gcd(12,30)=2*3=6
lcm(12,30)=2*2*3*5=60 (중복된 부분 제외(한 번만))

유클리드 호제법
두 양의 정수 a,b(a>b) a=bq+r(0<=r<b) (즉 r=a mod b)
a,b의 최대 공약수= b,r의 최대공약수

최소공배수 lcm(a,b)=a*b/gcd(a,b)

3개 이상의 수에 대해 반복적으로 계산
1,2,3일 때
1) gcd(1,2)=1
	lcm(1,2)=1*2/gcd(1,2)=2 이 값이 아래 gcd의 첫 input으로 들어감
2) gcd(2,3)=1
	lcm(2,3)=2*3/gcd(2,3)=6
*/

/*
유클리드 호제법
재귀함수
gcd(a, b) //최대공약수
{
	r=a mod b;
	if r == 0 then
	gcd(b, a % b);
}
lcm(a, b) //최소공배수
{
	a * b / gcd(a, b);
}
*/
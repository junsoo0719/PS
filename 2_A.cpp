#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	int cnt = 1;
	for (size_t i = 0; i < str.size() + 1; i++)
		cnt *= 2;
	cnt--;
	cout << cnt;
}
/*
int cnt = 0;
void function(string str, string current = "", int idx = 0)
{
	++cnt;
	if (idx == str.size())
	{
		cout << current << "\n";
		return; //base case
	} //여기까지 visit함수 역할 (visit 함수 먼저 있음)
	function(str, current, idx + 1); //left child
	function(str, current + str[idx], idx + 1); //right child
}
자식이 2개인 recursion tree를 이용해서 분석(재귀함수 2개)
binary tree 형태
visit 먼저 -> 왼쪽 자식 재귀함수 호출 -> 오른쪽 자식 재귀함수 호출
: preorder traversal
자식: idx값 1증가
왼쪽 자식: current 그대로
오른쪽 자식: current + 현재 idx 문자 추가(str[idx])
visit 함수 부분(current출력): 상수 시간 -> 각 노드 상수 시간 수행
함수 총 회출 횟수 구하면 됨(노드 개수)
idx -> 트리의 depth에 대응
depth	노드 개수
0		1(=2^0)
1		2(=2^1)
2		4(=2^2)
...		...
n		2^n
총 노드 개수: 등비수열의 합 = 초항(등비^항의개수 - 1) / (등비 - 1)
= 1(2^n+1 - 1) / (2 - 1) = 2^n+1 - 1
따라서 위의 함수 그대로 수행하면 O(2^n+1) time에 수행(=O(2^n))
n : 문자열의 길이

pow()함수: C++ 내장 함수
pow(a,n): a^n -> O(log n) time(반복문 사용, 분할정복 divide and conquer 전략 사용)
pow 함수 이용
pow(a, n)
{
	if(n == 0) return 1;
	tmp = pow(a, n/2);
	if(n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * a;
}

의사코드
cin >> str; //O(n) time, O(n) space
int n = str.size(); //O(1) time
int cnt = 1;
for(int i = 1; i <= n + 1; i++)
{ //O(n) time
	cnt *= 2;
} //2^(n+1)
cnt--;
전체 수행시간: O(n) time
전체 사용공간: O(n) space

									function("ab","",0) cnt: 1
			function("ab","",1) cnt: 2					function("ab","a",1) cnt: 5
function("ab","",2) 	function("ab","b",2)	function("ab","a",2)		function("ab","ab",2)
cnt: 3, print ""		cnt: 4, print "b"		cnt: 6, print "a"			cnt: 7, print "ab"



간단하게 생각하면 function이 한 번 호출될 때마다 cnt값을 1씩 증가시키기 때문에
function이 총 몇 번 호출되는지 계산하면 cnt값을 알 수 있다.
재귀 함수인 function함수의 base condition을 보면 idx==str.size()이기 때문에
idx값에만 초점을 맞추면 될 것 같다.
처음 함수 호출 때에는 idx가 0일 때 1번 호출되고
그 속에서 idx가 1인 함수가 2번 호출된다.
마찬가지로 idx가 1인 함수 안에서도 idx가 2인 함수가 2번씩 호출된다.
반복적으로 생각하면 
idx: 0일 때 2^0(1)번
idx: 1일 때 2^1(2)번
idx: 2일 때 2^2(4)번
...
idx: N일 때 2^N번

정답률
A 20/28
B 16/28
전체분반
A 110/146
B 82/146
*/
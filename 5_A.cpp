#include <iostream>
#include <stack>
#include <string>
using namespace std;

int t, h, q, c;
stack<char> st;

void binarySearch(int curnode)
{
	if (curnode == 1)
	{
		while (!st.empty())
		{
			char cur = st.top();
			st.pop();
			cout << cur;
		}
		cout << "\n";
		return;
	}
	if (curnode % 2 == 0)
		st.push('L');
	else
		st.push('R');
	binarySearch(curnode / 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> h >> q;
		while (q--)
		{
			cin >> c;
			//binarySearch(c);
			string ans = ""; //O(h) space
			while (c > 1)
			{ //O(h)
				string += (c % 2 == 0 ? 'L' : 'R'); //문자열로 출력
				c /= 2;
			}
			reverse(ans.begin(), ans.end()); //문자열을 뒤집는 함수 O(h)
			cout << ans << "\n";
			//혹은 원래 알던 스택을 사용해서 출력해도 됨
		}//전체 시간 복잡도: 테스트 케이스마다 O(qh) time
	}
}

/*
정답률
A 25/28
B 3/28
전체분반
A 115/146
B 26/146

완전 이진 트리
array로 표현할 수 O

루트 노드: 1번 인덱스
parent = child / 2
left = parent * 2 => parent = left / 2
right = parent * 2 + 1 => parent (right - 1) / 2
*/
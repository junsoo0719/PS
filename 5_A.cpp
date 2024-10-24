#include <iostream>
#include <stack>
using namespace std;

int t;

void binarySearch(stack<char>& st, int c)
{
	if (c == 1)
		return;
	if (c % 2 == 1)
		st.push('R');
	else
		st.push('L');
	binarySearch(st, c / 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int h, q;
		cin >> h >> q;
		for (int i = 0; i < q; i++)
		{
			int c;
			cin >> c;
			stack<char> st;
			binarySearch(st, c);
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << "\n";
		} //전체 시간 복잡도: 테스트 케이스마다 O(qh) time
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
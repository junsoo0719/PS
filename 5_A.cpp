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
				string += (c % 2 == 0 ? 'L' : 'R'); //���ڿ��� ���
				c /= 2;
			}
			reverse(ans.begin(), ans.end()); //���ڿ��� ������ �Լ� O(h)
			cout << ans << "\n";
			//Ȥ�� ���� �˴� ������ ����ؼ� ����ص� ��
		}//��ü �ð� ���⵵: �׽�Ʈ ���̽����� O(qh) time
	}
}

/*
�����
A 25/28
B 3/28
��ü�й�
A 115/146
B 26/146

���� ���� Ʈ��
array�� ǥ���� �� O

��Ʈ ���: 1�� �ε���
parent = child / 2
left = parent * 2 => parent = left / 2
right = parent * 2 + 1 => parent (right - 1) / 2
*/
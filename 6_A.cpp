#include <iostream>
#include <string>
using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int x, y;
		string s; //O(|s|) space
		cin >> x >> y;
		cin >> s;
		int cnt[10] = {};
		int remove_cnt = 0;
		int total_cost = 0;
		bool rune = false;
		for (size_t i = 0; i < s.size(); i++)
		{ //O(|s|) time
			if (s[i] == '3' || s[i] == '6' || s[i] == '9')
			{
				cnt[s[i] - '0']++;
				rune = true;
			}
			else
			{
				remove_cnt++;
				rune = false;
			}
			if ((rune == true && remove_cnt > 0) || i == s.size() - 1)
			{
				total_cost += min(x * remove_cnt, y + x);
				remove_cnt = 0;
			}
		}

		int max_spell = 10001;
		for (int i = 3; i <= 9; i += 3)
			max_spell = min(max_spell, cnt[i]);

		cout << total_cost << " " << max_spell << "\n";
	}
}

/*
 �����
A 25/28
B 10/28
��ü�й�
A 109/146
B 53/146

optimization problem (greedy algorithm)

���� �ؼ� �ڵ�
int cnt[3]; //3,6,9 �� ���� ���� ���
int eng=0;
int 
for i=0~s.size()-1
	if s[i]=='3'||'6'||'9'
		cnt[(int)(s[i]-'0') / 3 - 1]++;
		eng += min(x*count,x+y);
		count=0;
	else
		count++;
if count>0
	eng += min(x*count,x+y);
print eng, min(cnt[0], min(cnt[1],cnt[2]));

(�ǻ��ڵ�)
����� ����
	- cnt�迭: 3,6,9�� ����
	- remove_cnt: ���ӵ� ���ʿ��� ������ ����
	- total_cost: ���ʿ��� ���ڸ� ���ִ� �� �ʿ��� �� �������� �ּڰ�
	- rune(boolean): ���� Ž���ϴ� ���ڰ� �ʿ�����/���ʿ�����

���� Ž���ϴ� ���ڰ� 3,6,9�� �ϳ����
	�ش� ���� count 1����: cnt[s[i] - '0']++
	�ʿ��� ���ڶ�� ǥ��: rune = true

�ƴ϶��
	���ӵ� ���ʿ��� ������ ���� 1����: remove_cnt++
	���ʿ��� ���ڶ�� ǥ��: rune = false

���簡 �ʿ��� �����̸鼭 ���ʿ��� ���� ������ 0���� Ŭ ��
��, �������� ���ʿ��� ���ڰ� �־��� ��: rune == true && remove_cnt > 0
�Ǵ�
���ڿ��� ������ ������ ��
(�� ���� ���ʿ��� ���ڰ� �־����� ���� ���ǿ� ���Ե��� �����Ƿ� ���� �߰�)
: i == s.size() - 1 
	���ӵ� ���ʿ��� ���ڵ��� �ϳ��� ���� �� �ʿ��� ��������
	���ӵ� ���ʿ��� ���ڸ� �ϳ��� ���ڷ� �ٲ� �� �� ���ڸ� ���� �� �ʿ��� ������ ��

*/
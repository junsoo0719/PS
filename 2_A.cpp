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
	} //������� visit�Լ� ���� (visit �Լ� ���� ����)
	function(str, current, idx + 1); //left child
	function(str, current + str[idx], idx + 1); //right child
}
�ڽ��� 2���� recursion tree�� �̿��ؼ� �м�(����Լ� 2��)
binary tree ����
visit ���� -> ���� �ڽ� ����Լ� ȣ�� -> ������ �ڽ� ����Լ� ȣ��
: preorder traversal
�ڽ�: idx�� 1����
���� �ڽ�: current �״��
������ �ڽ�: current + ���� idx ���� �߰�(str[idx])
visit �Լ� �κ�(current���): ��� �ð� -> �� ��� ��� �ð� ����
�Լ� �� ȸ�� Ƚ�� ���ϸ� ��(��� ����)
idx -> Ʈ���� depth�� ����
depth	��� ����
0		1(=2^0)
1		2(=2^1)
2		4(=2^2)
...		...
n		2^n
�� ��� ����: �������� �� = ����(���^���ǰ��� - 1) / (��� - 1)
= 1(2^n+1 - 1) / (2 - 1) = 2^n+1 - 1
���� ���� �Լ� �״�� �����ϸ� O(2^n+1) time�� ����(=O(2^n))
n : ���ڿ��� ����

pow()�Լ�: C++ ���� �Լ�
pow(a,n): a^n -> O(log n) time(�ݺ��� ���, �������� divide and conquer ���� ���)
pow �Լ� �̿�
pow(a, n)
{
	if(n == 0) return 1;
	tmp = pow(a, n/2);
	if(n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * a;
}

�ǻ��ڵ�
cin >> str; //O(n) time, O(n) space
int n = str.size(); //O(1) time
int cnt = 1;
for(int i = 1; i <= n + 1; i++)
{ //O(n) time
	cnt *= 2;
} //2^(n+1)
cnt--;
��ü ����ð�: O(n) time
��ü ������: O(n) space

									function("ab","",0) cnt: 1
			function("ab","",1) cnt: 2					function("ab","a",1) cnt: 5
function("ab","",2) 	function("ab","b",2)	function("ab","a",2)		function("ab","ab",2)
cnt: 3, print ""		cnt: 4, print "b"		cnt: 6, print "a"			cnt: 7, print "ab"



�����ϰ� �����ϸ� function�� �� �� ȣ��� ������ cnt���� 1�� ������Ű�� ������
function�� �� �� �� ȣ��Ǵ��� ����ϸ� cnt���� �� �� �ִ�.
��� �Լ��� function�Լ��� base condition�� ���� idx==str.size()�̱� ������
idx������ ������ ���߸� �� �� ����.
ó�� �Լ� ȣ�� ������ idx�� 0�� �� 1�� ȣ��ǰ�
�� �ӿ��� idx�� 1�� �Լ��� 2�� ȣ��ȴ�.
���������� idx�� 1�� �Լ� �ȿ����� idx�� 2�� �Լ��� 2���� ȣ��ȴ�.
�ݺ������� �����ϸ� 
idx: 0�� �� 2^0(1)��
idx: 1�� �� 2^1(2)��
idx: 2�� �� 2^2(4)��
...
idx: N�� �� 2^N��

�����
A 20/28
B 16/28
��ü�й�
A 110/146
B 82/146
*/
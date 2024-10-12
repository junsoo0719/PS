#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string s;
string res;

char check(string str)
{ //�־��� ��� ���ڿ��� ���̸�ŭ üũ �ʿ� O(str.size())
	for (size_t i = 1; i < str.size(); i++)
	{ //�־��� ���ڿ��� �ѹ��� ������� �ʴ� ��� false ����
		if (str[i] != str[i - 1])
			return false;
	} //�־��� ���ڿ��� ��� 0 �Ǵ� 1�� ��� true ����
	return true;
}

void compress(string str) //T(str.size())
{
	if (check(str)) //O(str.size())
	{
		res += str[0];
		return; //�ѹ��� ���� ������ ���ڿ��� ��� str[0]���� ���� �� ����
	}
	size_t size = str.size();
	res += "B"; //�ѹ��� ���� �Ұ����� ��� B�� �߰��ϰ� �ݾ� ������ ���
	compress(str.substr(0, size / 2)); //substr(������ġ, ����): �κй��ڿ� ����
	compress(str.substr(size / 2)); //������ġ ~ ������
} //2T(str.size()/2)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> s;
		compress(s); //T(N) = O(NlgN) �ð����⵵
		cout << res << "\n";
		res = ""; //��� ���ڿ� �ʱ�ȭ
	}
}

/*
���� �Է� ���� 2�������� -> Ȧ���� �־����� ��� X, ������ �ɰ��� ����
�������⵵ O(N)
recursion tree�� binary tree ����
�� path�� ���� space�� ���
= N + N/2 + N/4 + ... + 1
= N + N(1/2)/(1-1/2) = 2N => O(N) space
			N
	N/2				N/2
N/4		N/4		 N/4	 N/4
merge sort�� ���� -> postorder traversal

�����
A 12/28
B 3/28
��ü�й�
A 69/146
B 12/96
*/
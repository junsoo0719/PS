#include <iostream>
#include <algorithm>
using namespace std;

int t;
int arr[27]; //�л��� �⿩�� space N
int ass[27]; //���� ���� ���� space M
// ��ü ��� ���� O(1) N,M�� 26�� ���� �ʱ� ���� (������ O(N)���� �����ص� ��)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n, m; //�л� ��, �� ����
		cin >> n >> m;
		for (int i = 0; i < n; i++) //O(N)
			cin >> arr[i];
		for (int i = 0; i < m; i++) //O(M)
			cin >> ass[i];
		for (int i = 0; i < m; i++) //O(M)
		{
			int tm;	//���� �л� ��
			cin >> tm;
			int minT = 1000; //���� ���� �⿩��
			for (int j = 0; j < tm; j++) //O(N) �� ����, ���� �л� �� �ᱹ ��ü ���� Ƚ���� O(N)
			{
				char c; //������ �����Ǵ� �л�
				cin >> c;
				minT = min(minT, arr[c - 65]); //c - 'A'�� �ᵵ ��
			}
			cout << minT * ass[i] << " ";
		}
		cout << "\n";
	} //��ü ����ð� O(N) (M<=N)
}

/*
�����
A 21/35
B 9/35
��ü�й�
A 104/183
B 59/183

<Basic Idea>
������ �������� �⿩�� ������ ��ȸ�ϸ鼭 �ּ� �⿩�� Ȯ��
���� �ּ� �⿩���� ���� ������ ���� ���� ���
1<N<=26�̹Ƿ� N���� �м��ص� �ǰ� ���� �����̱� ������ constant�� �м��ص� ������
�׷��� �Է� ������ N���� �м��ϴ� ���� �� ���ƺ���
*/
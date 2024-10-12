#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second
using pii = pair<int, int>;

int t, n;
string idname[11], brname[11];
int idgoal[11], brgoal[11];

int findidxid(string s)
{
	for (int i = 0; i < 10; i++)
	{
		if (idname[i] == s)
			return i;
		if (idname[i] == "")
		{
			idname[i] = s;
			return i;
		}
	}
	return 0;
}

int findidxbr(string s)
{
	for (int i = 0; i < 10; i++)
	{
		if (brname[i] == s)
			return i;
		if (brname[i] == "")
		{
			brname[i] = s;
			return i;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> n;
		priority_queue<pii, vector<pii>, less<pii>> idpq;
		priority_queue<pii, vector<pii>, less<pii>> brpq;
		fill(idname, idname + 11, "");
		fill(brname, brname + 11, "");
		fill(idgoal, idgoal + 11, 0);
		fill(brgoal, brgoal + 11, 0);
		int idscore = 0;
		int brscore = 0;
		
		for (int i = 0; i < n; i++)
		{
			int a, b;
			string c;
			cin >> a >> b >> c;
			if (idscore != a)
			{//�δ��� ����
				int curidx = findidxid(c);
				idgoal[curidx] += (a - idscore);
				//cout << "curidx: " << curidx << "   idscore: " << idscore << "   idgoal[curidx]: " << idgoal[curidx] << "\n";
				idpq.push({ idgoal[curidx],curidx });
				idscore = a;
			}
			else
			{//����� ����
				int curidx = findidxbr(c);
				brgoal[curidx] += (b - brscore);
				//cout << "curidx: " << curidx << "   brscore: " << brscore << "   brgoal[curidx]: " << brgoal[curidx] << "\n";
				brpq.push({ brgoal[curidx],curidx });
				brscore = b;
			}
		}
		if (idscore > brscore)
		{
			auto mvp = idpq.top();
			cout << idname[mvp.Y] << " " << mvp.X << "\n";
		}
		else
		{
			auto mvp = brpq.top();
			cout << brname[mvp.Y] << " " << mvp.X << "\n";
		}
	}
}

/*
�����
A 17/28
B 1/28
��ü�й�
A 93/146
B 8/146

map �ڷᱸ�� (key, value) = (����, ������ ��)
red-black Ʈ�� ����
key �� �������� ������ ����
���� ���⵵ O(log n)

unordered map
�ؽ� ���̺� ������� O(1) ���⵵
�����͸� ������ �ʿ� �����Ƿ� unordered map ���

- ������ (����, ������) unordered_map ����
- �� ���� ��� �־��� ������ ������ ��ϵ� ������ ���Ͽ� ��� ���� �����Ͽ�����
�Ǵ��ϰ�, ������ ������ ���� ������ ����
- ���� �¸��� ���� unordered_map ��ȸ�Ͽ� ���� �� ������ ���� ���� ū ���� ����

int before_a=0,before_b=0;
unordered_map<string,int> score_a, score_b; //O(n+k) space (bucket ������ k)
for i=1 to n //n�� �ݺ��̹Ƿ� O(n) time
	if before_a != a
		score_a[c] = score_a[c] + (a-before_a) //O(1)
		before_a=a;
	else
		score_b[c] = score_b[c] + (b-before_b)
		before_b=b;
	
	string mvp
	int mvp_score=0;
	if before_a > before_b
		for it=score_a.begin() to score_a.end()-1
			if *it.second > mvp_score
				mvp = *it.first
				mvp_score = *it.second
	else
		
			
(����)
map �ð����⵵ �м� �κп��� ��ü ������ n�� ��
m�̶�� �߰� ���� ���� n���θ� ��Ÿ�� ���� �������?
*/
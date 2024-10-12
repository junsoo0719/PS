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
			{//인덕팀 득점
				int curidx = findidxid(c);
				idgoal[curidx] += (a - idscore);
				//cout << "curidx: " << curidx << "   idscore: " << idscore << "   idgoal[curidx]: " << idgoal[curidx] << "\n";
				idpq.push({ idgoal[curidx],curidx });
				idscore = a;
			}
			else
			{//비룡팀 득점
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
정답률
A 17/28
B 1/28
전체분반
A 93/146
B 8/146

map 자료구조 (key, value) = (선수, 점수의 합)
red-black 트리 형태
key 값 기준으로 데이터 정렬
삽입 복잡도 O(log n)

unordered map
해시 테이블 기반으로 O(1) 복잡도
데이터를 정렬할 필요 없으므로 unordered map 사용

- 팀별로 (선수, 점수합) unordered_map 생성
- 각 점수 기록 주어질 때마다 이전에 기록된 점수와 비교하여 어느 팀이 득점하였는지
판단하고, 득점한 선수에 대해 점수합 갱신
- 최종 승리한 팀의 unordered_map 순회하여 선수 중 점수의 합이 가장 큰 선수 구함

int before_a=0,before_b=0;
unordered_map<string,int> score_a, score_b; //O(n+k) space (bucket 사이즈 k)
for i=1 to n //n번 반복이므로 O(n) time
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
		
			
(질문)
map 시간복잡도 분석 부분에서 전체 선수가 n일 때
m이라는 추가 변수 없이 n으로만 나타낼 수는 없을까요?
*/
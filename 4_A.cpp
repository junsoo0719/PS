#include <iostream>
#include <unordered_map>
using namespace std;

#define X first
#define Y second
int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		unordered_map<string, int> a_score, b_score;
		int a_before = 0;
		int b_before = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			string c;
			cin >> c;
			if (a != a_before)
			{ // 해당 key의 value 존재하지 않으면 자동 기본값(0) 초기화
				a_score[c] += (a - a_before);
				a_before = a;
			}
			else
			{
				b_score[c] += (b - b_before);
				b_before = b;
			}
		}
		string mvp_name;
		int mvp_score = 0;
		if (a_before > b_before)
		{
			for (auto cur : a_score)
			{
				if (cur.Y > mvp_score)
				{
					mvp_score = cur.Y;
					mvp_name = cur.X;
				}
			}
		}
		else
		{
			for (auto cur : b_score)
			{
				if (cur.Y > mvp_score)
				{
					mvp_score = cur.Y;
					mvp_name = cur.X;
				}
			}
		}
		cout << mvp_name << " " << mvp_score << "\n";
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
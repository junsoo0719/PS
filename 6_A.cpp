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
 정답률
A 25/28
B 10/28
전체분반
A 109/146
B 53/146

optimization problem (greedy algorithm)

수업 해설 코드
int cnt[3]; //3,6,9 룬 숫자 개수 기록
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

(의사코드)
사용할 변수
	- cnt배열: 3,6,9의 개수
	- remove_cnt: 연속된 불필요한 숫자의 개수
	- total_cost: 불필요한 숫자를 없애는 데 필요한 총 에너지의 최솟값
	- rune(boolean): 현재 탐색하는 숫자가 필요한지/불필요한지

현재 탐색하는 숫자가 3,6,9중 하나라면
	해당 숫자 count 1증가: cnt[s[i] - '0']++
	필요한 숫자라고 표시: rune = true

아니라면
	연속된 불필요한 숫자의 개수 1증가: remove_cnt++
	불필요한 숫자라고 표시: rune = false

현재가 필요한 숫자이면서 불필요한 숫자 개수가 0보다 클 때
즉, 직전까지 불필요한 숫자가 있었을 때: rune == true && remove_cnt > 0
또는
문자열의 마지막 숫자일 때
(이 경우는 불필요한 숫자가 있었더라도 위의 조건에 포함되지 않으므로 조건 추가)
: i == s.size() - 1 
	연속된 불필요한 숫자들을 하나씩 지울 때 필요한 에너지와
	연속된 불필요한 숫자를 하나의 숫자로 바꾼 뒤 그 숫자를 지울 때 필요한 에너지 중

*/
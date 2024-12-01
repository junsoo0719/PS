#include <iostream>
#include <queue>
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
		int n, inha;
		cin >> n;
		cin >> inha;
		priority_queue<int> pq; // O(N) space
		for (int i = 0; i < n - 1; i++)
		{
			int sticker;
			cin >> sticker;
			if (sticker >= inha) // 추가
				pq.push(sticker); // O(N log N) time
		}
		
		int cnt = 0;
		while (!pq.empty() && inha <= pq.top())
		{
			int max_sticker = pq.top();
			pq.pop();
			inha++;
			cnt++;
			pq.push(max_sticker - 1);
		}
		cout << cnt << "\n";

		/*int max_sticker = 0;
		while (!pq.empty() && inha <= pq.top())
		{
			max_sticker = pq.top();
			pq.pop();
			pq.push(max_sticker - 1);
			inha++;
			move_cnt++;
		}*/
	} // 전체 O((N + K)log N) time
}

/*
 정답률
A 12/28
B 0/28
전체분반
A 57/135
B 10/135

최악: 모든 학생 중 인하를 제외한 한 명이 모든 표를 다 가져간 경우
-> 해당 학생의 보드판에서 스티커를 모두 떼어내어 인하의 보드판에
붙여야 하므로, 스티커의 개수에 대해 k/2 + 1번 수행해야 함.

ComputeCnt()
int cnt = 0
while !pq.empty() && inha <= pq.top()
	int top = pq.top()
	pq.pop()
	pq.push(top-1)
	inha++
	cnt++
return cnt
*/
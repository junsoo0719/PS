#include <iostream>
#include <algorithm>
using namespace std;

int t;
int arr[27]; //학생별 기여도 space N
int ass[27]; //팀별 과제 점수 space M
// 전체 사용 공간 O(1) N,M은 26을 넘지 않기 때문 (변수로 O(N)으로 생각해도 됨)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--)
	{
		int n, m; //학생 수, 팀 개수
		cin >> n >> m;
		for (int i = 0; i < n; i++) //O(N)
			cin >> arr[i];
		for (int i = 0; i < m; i++) //O(M)
			cin >> ass[i];
		for (int i = 0; i < m; i++) //O(M)
		{
			int tm;	//팀별 학생 수
			cin >> tm;
			int minT = 1000; //팀별 최저 기여도
			for (int j = 0; j < tm; j++) //O(N) 팀 개수, 팀별 학생 수 결국 전체 연산 횟수는 O(N)
			{
				char c; //팀별로 배정되는 학생
				cin >> c;
				minT = min(minT, arr[c - 65]); //c - 'A'로 써도 됨
			}
			cout << minT * ass[i] << " ";
		}
		cout << "\n";
	} //전체 수행시간 O(N) (M<=N)
}

/*
정답률
A 21/35
B 9/35
전체분반
A 104/183
B 59/183

<Basic Idea>
팀별로 팀원들의 기여도 정보를 순회하면서 최소 기여도 확인
팀별 최소 기여도에 과제 점수를 곱한 값을 출력
1<N<=26이므로 N으로 분석해도 되고 작은 숫자이기 때문에 constant로 분석해도 괜찮음
그래도 입력 변수인 N으로 분석하는 것이 더 좋아보임
*/
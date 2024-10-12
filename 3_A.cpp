#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string s;
string res;

char check(string str)
{ //최악의 경우 문자열의 길이만큼 체크 필요 O(str.size())
	for (size_t i = 1; i < str.size(); i++)
	{ //주어진 문자열이 한번에 압축되지 않는 경우 false 리턴
		if (str[i] != str[i - 1])
			return false;
	} //주어진 문자열이 모두 0 또는 1일 경우 true 리턴
	return true;
}

void compress(string str) //T(str.size())
{
	if (check(str)) //O(str.size())
	{
		res += str[0];
		return; //한번에 압축 가능한 문자열인 경우 str[0]으로 압축 후 리턴
	}
	size_t size = str.size();
	res += "B"; //한번에 압축 불가능한 경우 B를 추가하고 반씩 나눠서 재귀
	compress(str.substr(0, size / 2)); //substr(시작위치, 길이): 부분문자열 추출
	compress(str.substr(size / 2)); //시작위치 ~ 끝까지
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
		compress(s); //T(N) = O(NlgN) 시간복잡도
		cout << res << "\n";
		res = ""; //결과 문자열 초기화
	}
}

/*
문제 입력 조건 2의제곱수 -> 홀수로 주어지는 경우 X, 반으로 쪼개기 쉬움
공간복잡도 O(N)
recursion tree가 binary tree 형태
한 path에 대한 space만 사용
= N + N/2 + N/4 + ... + 1
= N + N(1/2)/(1-1/2) = 2N => O(N) space
			N
	N/2				N/2
N/4		N/4		 N/4	 N/4
merge sort와 유사 -> postorder traversal

정답률
A 12/28
B 3/28
전체분반
A 69/146
B 12/96
*/
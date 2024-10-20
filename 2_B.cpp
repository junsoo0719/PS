#include <iostream>
#include <stack>
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
		string str;
		cin >> str;
		stack<string> st;
		bool tagRead = false;
		string curTag = "";
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '<')
			{
				tagRead = true;
			}
			else if (tagRead && str[i] == '/')
			{
				st.pop();
				tagRead = false;
			}
			else if (tagRead && str[i] == '>')
			{
				st.push(curTag);
				curTag = "";
				tagRead = false;
			}
			else if (tagRead)
			{
				curTag += str[i];
			}
		}
		while (!st.empty())
		{
			auto cur = st.top();
			st.pop();
			cout << "</" << cur << ">";
		}
		cout << "\n";
	}
}
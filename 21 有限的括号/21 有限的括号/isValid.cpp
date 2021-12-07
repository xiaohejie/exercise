#include<iostream>
#include <map>
#include <stack>
using namespace std;
bool isValid(string s) {
	int length = s.size();
	if (length % 2 == 1)
	{
		//若为单数
		return false;
	}
	map<char, char>ch = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
	//进行遍历
	stack<char>stk;
	for (int i = 0; i < length; i++)
	{
		//找到键值右括号
		if (ch.count(s[i]))
		{
			if (stk.empty() || stk.top() != ch[s[i]])
			{
				return false;
			}
			stk.pop();
		}
		else
		{//找的是左括号
			stk.push(s[i]);
		}
	}
	return stk.empty();
}
int main() {
	system("pause");
	return 0;
}
#include<iostream>
#include <map>
#include <stack>
using namespace std;
bool isValid(string s) {
	int length = s.size();
	if (length % 2 == 1)
	{
		//��Ϊ����
		return false;
	}
	map<char, char>ch = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
	//���б���
	stack<char>stk;
	for (int i = 0; i < length; i++)
	{
		//�ҵ���ֵ������
		if (ch.count(s[i]))
		{
			if (stk.empty() || stk.top() != ch[s[i]])
			{
				return false;
			}
			stk.pop();
		}
		else
		{//�ҵ���������
			stk.push(s[i]);
		}
	}
	return stk.empty();
}
int main() {
	system("pause");
	return 0;
}
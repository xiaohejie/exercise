#include<iostream>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
	{
		return "";
	}
	string res = strs[0];		//ȡ����һ��Ԫ��
	for (int i = 1; i < strs.size(); i++)
	{
		//�ӵڶ���Ԫ�ؿ�ʼ����
		string curString = strs[i];
		int length = res.size() > curString.size() ? curString.size() : res.size();
		if (length == 0)
		{
			//���ڿ�Ԫ��
			return "";
		}
		for (int j = 0; j < length; j++)
		{
			if (res[j] != curString[j])
			{
				res = res.substr(0, j);
				break;
			}
		}
		res = res.substr(0, length);
	}
}
int main() {
	system("pause");
	return 0;
}
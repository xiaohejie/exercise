#include <iostream>
using namespace std;
#include <string.h>
/*
	���������0��n������֤�飬������ȴ����һ�����ҳ�����ʱ�临�Ӷ�O(n)
*/
int Exercise2(int num[] , int len) {
	int res = 0;
	for (size_t i = 0; i < len; i++)
	{
		//������֮���ֻ��ȱ�ٵ��Ǹ�����û�н������
		res ^= num[i];
	}
	for (size_t i = 0; i <= len; i++)
	{
		res ^= i;
	}
	return res;
}
int main() {
	int num[] = { 0,1,2,4,6 ,5,7 };
	int len = sizeof(num) / sizeof(num[1]);
	int res = Exercise2(num, len);
	cout << res << endl;
  	system("pause");
	return 0;
}
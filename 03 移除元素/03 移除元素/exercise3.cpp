#include <iostream>
using namespace std;
/*
	ɾ�����������е��ظ���
		����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�
		ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
	ע�⣺��ʹ�ö��������ռ䣬��ԭ���޸��������鲢��ʹ��O(1)����ռ�����������
*/
int exercise(int* num , int len) {
	if (len == 0)
	{
		return 0;
	}
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		if (num[i - 1] != num[i])
		{
			num[j] = num[i - 1];
			j++;
		}
	}
	num[j] = num[len - 1];
	j++;
	for (int i = 0; i < j; i++)
	{
		cout << num[i] << "  ";
	}
	cout << endl;
	return j;
}
int main() {
	int num[] = { 1,1,1,2,2,5,5,5,8,8,8,9,9,9,10,10,10,22 };
	int len = sizeof(num) / sizeof(num[0]);
	int res = exercise(num, len);
	cout << res << endl;
	system("pause");
	return 0;
}
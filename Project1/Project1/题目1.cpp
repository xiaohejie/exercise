#include <iostream>
using namespace std;
/*
	һ����������nums���������������֮�⣬�������ֶ����������Ρ�
	��д��������������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
*/
//ֻ��һ��������һ��������ȫ������
int FindNum(int nums[] , int len) {
	int a = 0;
	for (int i = 0; i < len; i++)
	{
		a ^= nums[i];
	}
	return a;
}
//�����������ǵ�����
int FindNums(int nums[], int len) {
	//1���Ƚ��������ֽ�����򣬵õ��ľ���ֻ��һ�����������ֵ����
	//2��Ȼ��ȡ���õ��Ķ������еĳ���1��һλ
	//3�������и�λ�ķ���һ�������У������и�λ�ķ�����һ��������
	//4���ڽ���FindNum�������͵õ��������������
}
int main() {
	int nums[] = { 0 ,12,13,1,0,1,12,13,15,62,62 };
	int len = sizeof(nums)/sizeof(nums[0]);
	int res = FindNum(nums , len);
	cout << res << endl;
	system("pause");
	return 0;
}
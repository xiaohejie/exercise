#include <iostream>
using namespace std;
/*
	һ����������nums���������������֮�⣬�������ֶ����������Ρ�
	��д��������������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
*/
//ֻ��һ��������һ��������ȫ������
int FindNum(int num[] , int len) {
	int a = 0;
	for (int i = 0; i < len; i++)
	{
		a ^= num[i];
	}
	return a;
}
//�����������ǵ�����
int gVal[2] = { 0 };
int* FindNums(int nums[], int lens) {
	int mVal = 0;
	int i = 0;
	int mStandard = 0;

	memset(gVal ,0x0 , sizeof(gVal));//����ռ�

	if (lens>2)
	{
		//�Ƚ��������ֽ�����򣬵õ��ľ���ֻ��һ�����������ֵ����
		for ( i = 0; i < lens; i++)
		{
			mVal ^= nums[i];
		}
		//Ȼ��ȡ���õ��Ķ������еĳ���1��һλ
		for ( i = 0; i < lens; i++)
		{
			if (((mVal >> i) & 1) == 1) {
				mStandard = i;
				break;
			}
		}

		for ( i = 0; i < lens; i++)
		{
			if (nums[i] & (1 << mStandard)) {
				gVal[0] ^= nums[i];
			}
			else
			{
				gVal[1] ^= nums[i];
			}
		}
	}
	return gVal;
	////1���Ƚ��������ֽ�����򣬵õ��ľ���ֻ��һ�����������ֵ����
	//int num = FindNum(nums, lens);
	//int temp = 0;
	////2��Ȼ��ȡ���õ��Ķ������еĳ���1��һλ
	//for (int i = 0; ; i++)
	//{
	//	int a = 0;
	//	a = num % 2;
	//	num = num >> 1;
	//	temp++;
	//	if (a & 1 == 0) {
	//		break;
	//	}
	//}
	////3�������и�λ�ķ���һ�������У������и�λ�ķ�����һ��������
	//int nums1[10];
	//int nums2[10];
	//for (int i = 0; i < lens; i++)
	//{
	//	
	//}
	////4���ڽ���FindNum�������͵õ��������������
}
int main() {
	int num[] = { 0 ,12,13,1,0,1,12,13,15,62,62 };
	int len = sizeof(num) / sizeof(num[0]);
	int res = FindNum(num, len);

	int nums[] = { 0 ,12,13,1,0,1,12,6,13,15,62,62 };
	int lens = sizeof(nums) / sizeof(nums[0]);
	int* ress = FindNums(nums, lens);

	cout << ress[0] <<  "\t" << ress[1] << endl;
	system("pause");
	return 0;
}
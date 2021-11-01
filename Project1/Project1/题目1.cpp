#include <iostream>
using namespace std;
/*
	一个整形数组nums里面除了两个数字之外，其他数字都出现了两次。
	请写出程序中这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)
*/
//只有一个数字是一个，其余全是两个
int FindNum(int num[] , int len) {
	int a = 0;
	for (int i = 0; i < len; i++)
	{
		a ^= num[i];
	}
	return a;
}
//有两个数字是单个的
int gVal[2] = { 0 };
int* FindNums(int nums[], int lens) {
	int mVal = 0;
	int i = 0;
	int mStandard = 0;

	memset(gVal ,0x0 , sizeof(gVal));//清理空间

	if (lens>2)
	{
		//先将所有数字进行异或，得到的就是只有一个的两个数字的异或
		for ( i = 0; i < lens; i++)
		{
			mVal ^= nums[i];
		}
		//然后取出得到的二进制中的出现1的一位
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
	////1、先将所有数字进行异或，得到的就是只有一个的两个数字的异或
	//int num = FindNum(nums, lens);
	//int temp = 0;
	////2、然后取出得到的二进制中的出现1的一位
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
	////3、将含有该位的放在一个数组中，不含有该位的放在另一个数组中
	//int nums1[10];
	//int nums2[10];
	//for (int i = 0; i < lens; i++)
	//{
	//	
	//}
	////4、在进行FindNum操作，就得到我们所需的数字
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
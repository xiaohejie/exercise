#include <iostream>
using namespace std;
/*
	一个整形数组nums里面除了两个数字之外，其他数字都出现了两次。
	请写出程序中这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)
*/
//只有一个数字是一个，其余全是两个
int FindNum(int nums[] , int len) {
	int a = 0;
	for (int i = 0; i < len; i++)
	{
		a ^= nums[i];
	}
	return a;
}
//有两个数字是单个的
int FindNums(int nums[], int len) {
	//1、先将所有数字进行异或，得到的就是只有一个的两个数字的异或
	//2、然后取出得到的二进制中的出现1的一位
	//3、将含有该位的放在一个数组中，不含有该位的放在另一个数组中
	//4、在进行FindNum操作，就得到我们所需的数字
}
int main() {
	int nums[] = { 0 ,12,13,1,0,1,12,13,15,62,62 };
	int len = sizeof(nums)/sizeof(nums[0]);
	int res = FindNum(nums , len);
	cout << res << endl;
	system("pause");
	return 0;
}
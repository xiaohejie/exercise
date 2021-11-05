#include <iostream>
using namespace std;
/*
	删除排序数组中的重复项
		给定一个排序树组，你需要在原地删除重复出现的元素，
		使得每个元素只出现一次，返回移除后数组的新长度。
	注意：不使用额外的数组空间，在原地修改输入数组并在使用O(1)额外空间的条件下完成
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
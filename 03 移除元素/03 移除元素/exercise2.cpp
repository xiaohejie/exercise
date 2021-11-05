#include <iostream>
using namespace std;
void func(int* nums , int x , int len) {
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != x)
		{
			nums[j] = nums[i];
			cout << nums[j] << "  ";
			j++;
		}
	}
	cout << endl;
	
}
void test1() {
	int nums[] = { 1,3,5,5,6,4,5,8,9,2,85,6,2,5,5,35 };
	int x = 5;
	int len = sizeof(nums) / sizeof(nums[0]);
	func(nums , x , len);
}
int main2() {
	test1();
	system("pause");
	return 0;
}
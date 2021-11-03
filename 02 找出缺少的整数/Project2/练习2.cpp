#include <iostream>
using namespace std;
#include <string.h>
/*
	数组包含从0到n的所有证书，但其中却少了一个，找出来，时间复杂度O(n)
*/
int Exercise2(int num[] , int len) {
	int res = 0;
	for (size_t i = 0; i < len; i++)
	{
		//异或完成之后就只有缺少的那个数字没有进行异或
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
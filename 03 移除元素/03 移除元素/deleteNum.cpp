#include "deleteNum.h"

//需要进行初始化
void deleteInit(DL* nums) {
	nums->a = (int*)malloc(sizeof(int) * 4);
	if (nums->a == NULL)
	{
		cout << "申请内存失败！" << endl;
		exit(-1);
	}
	nums->size = 0;
	nums->capacity = 4;

}

//进行打印
void deletePrint(DL* nums) {
	assert(nums);
	for (size_t i = 0; i < nums->size; i++)
	{
		cout << nums->a[i] << "  ";
	}
	cout << endl;
}

//检查扩容
void SeqListCheckCapacity(DL* nums) {
	assert(nums);
	//如果满了需要增容
	if (nums->size >= nums->capacity)
	{
		nums->capacity *= 2;
		//增容使用realloc
		nums->a = (int*)realloc(nums->a , sizeof(int) * nums->capacity);

		if (nums->a == NULL)
		{
			cout << "申请内存失败！" << endl;
			exit(-1);
		}
	}
}

void deleteNum(DL* nums, int x) {

}


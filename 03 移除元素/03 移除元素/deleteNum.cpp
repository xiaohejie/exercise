#include "deleteNum.h"

//��Ҫ���г�ʼ��
void deleteInit(DL* nums) {
	nums->a = (int*)malloc(sizeof(int) * 4);
	if (nums->a == NULL)
	{
		cout << "�����ڴ�ʧ�ܣ�" << endl;
		exit(-1);
	}
	nums->size = 0;
	nums->capacity = 4;

}

//���д�ӡ
void deletePrint(DL* nums) {
	assert(nums);
	for (size_t i = 0; i < nums->size; i++)
	{
		cout << nums->a[i] << "  ";
	}
	cout << endl;
}

//�������
void SeqListCheckCapacity(DL* nums) {
	assert(nums);
	//���������Ҫ����
	if (nums->size >= nums->capacity)
	{
		nums->capacity *= 2;
		//����ʹ��realloc
		nums->a = (int*)realloc(nums->a , sizeof(int) * nums->capacity);

		if (nums->a == NULL)
		{
			cout << "�����ڴ�ʧ�ܣ�" << endl;
			exit(-1);
		}
	}
}

void deleteNum(DL* nums, int x) {

}


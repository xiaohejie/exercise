/*
	partition:
		����һ�������ͷ�ڵ� head ��һ���ض�ֵ x ��
		�����������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
*/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* lessHead, * lessHead1, * moreHead, * moreHead1;
	lessHead = lessHead1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	moreHead = moreHead1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessHead->next = moreHead->next = moreHead1->next = NULL;
	while (head)
	{
		if (head->val < x) {
			lessHead->next = head;
			head = head->next;
			lessHead = lessHead->next;
		}
		else
		{
			moreHead->next = head;
			head = head->next;
			moreHead = moreHead->next;
		}
	}
	lessHead->next = moreHead1->next;
	moreHead->next = NULL;		//������Ҫ�����ÿգ�����������ѭ������������P12 25�������ң�
	struct ListNode* newHead = lessHead1->next;
	free(lessHead1);
	return newHead;
} 
int main() {
	system("pause");
	return 0;
}
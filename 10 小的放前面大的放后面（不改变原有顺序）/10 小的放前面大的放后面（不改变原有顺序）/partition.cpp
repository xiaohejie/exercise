/*
	partition:
		给你一个链表的头节点 head 和一个特定值 x ，
		请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
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
	moreHead->next = NULL;		//这里需要进行置空，否则会出现死循环（比特鹏哥P12 25分钟左右）
	struct ListNode* newHead = lessHead1->next;
	free(lessHead1);
	return newHead;
} 
int main() {
	system("pause");
	return 0;
}
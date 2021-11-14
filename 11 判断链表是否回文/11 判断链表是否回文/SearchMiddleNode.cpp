//寻找链表中间元素
#include "SearchMiddleNode.h"
struct ListNode* SearchMiddleNode(struct ListNode* head) {
	ListNode* prev = NULL;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = NULL;
	return slow;
}
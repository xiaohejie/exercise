//将链表进行逆置
#include "ReserveList.h"
struct ListNode* ReserveList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* n1 = NULL;
	ListNode* n2 = head;
	ListNode* n3 = head->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;
}
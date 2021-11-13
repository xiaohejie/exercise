#include <iostream>
using namespace std;
/*
	合并两个有序链表：
		
*/
struct ListNode {
	int val;
	struct ListNode* next;

};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct ListNode* newhead = NULL, *tail = NULL;
	if (l1->val <= l2->val)
	{
		newhead = tail = l1;
		l1 = l1->next; 
	}
	else
	{
		newhead = tail = l2;
		l2 = l2->next;
	}
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
	{
		tail->next = l1;	//直接将后面所有都赋给tail
	}
	else
	{
		tail->next = l2;	//直接将后面所有都赋给tail
	}
	return newhead;
}
int main() {
	system("pause");
	return 0;
}
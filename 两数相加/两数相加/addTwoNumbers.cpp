#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;	
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* p = l1;
	ListNode* q = l2;
	int count1 = 1, count2 = 1;
	while (p->next)
	{
		count1++;
		p = p->next;
	}
	while (q->next)
	{
		count2++;
		q = q->next;
	}
	if (count1 < count2)
	{
		//链表l1元素少
		for (int i = 1; i <= count2 - count1; i++)
		{
			p->next = new ListNode(0);
			p = p->next;
		}
	}
	else
	{
		//链表l2元素少
		for (int i = 1; i <= count1 - count2; i++)
		{
			q->next = new ListNode(0);
			q = q->next;
		}
	}
	bool isOver = 0;
	ListNode* phead1 = l1;
	ListNode* phead2 = l2;
	ListNode* resList = new ListNode(-1);
	ListNode* res = resList;
	while (phead1) {
		int sum = isOver + phead1->val + phead2->val;		//得到相加结果
		if (sum > 9)
		{
			isOver = 1;
		}
		else {
			isOver = 0;
		}
		res->next = new ListNode(sum % 10);
		res = res->next;

		phead1 = phead1->next;
		phead2 = phead2->next;
	}
	if (isOver)
	{
		res->next = new ListNode(1);
		res = res->next;
	}
	return resList;
	
}
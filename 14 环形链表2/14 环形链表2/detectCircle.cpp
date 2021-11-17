#include <iostream>
using namespace std;
struct ListNode {
public:
	int val;
	struct ListNode* next;
};
//方法1：
ListNode* detectCycle(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* prev = NULL;
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	//找出快慢指针相交的点
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			prev->next = NULL;
			break;
		}
	}
	ListNode* meet = head;
	int l1 = 0, l2 = 0;
	while (meet)
	{
		meet = meet->next;
		l1++;
	}
	while (slow)
	{
		slow = slow->next;
		l2++;
	}
	ListNode* longhead = meet;
	ListNode* shorthead = slow;
	if (l2 > l1)
	{
		longhead = slow;
		shorthead = meet;
	}
	int gap = abs(l1 - l2);
	while (gap--)
	{
		longhead = longhead->next;
	}
	while (shorthead)
	{
		if (longhead == shorthead)
		{
			return longhead;
		}
		longhead = longhead->next;
		shorthead = shorthead->next;
	}
	return NULL;
}

//方法2：
ListNode* detectCycle2(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{ 
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	ListNode* meet = fast;
	while (head != meet)
	{
		meet = meet->next;
		head = head->next;
	}
	return meet;
}
int main() {
	system("pause");
	return 0;
}
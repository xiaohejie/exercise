#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
};
ListNode* insertionSortLis1t(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* sortHead = head;
	ListNode* cur = head->next;
	sortHead->next = NULL;
	while (cur)
	{
		ListNode* next = cur->next;
		//��cur���뵽sortHead�����У����ұ�������
		if (cur->val <= sortHead->val)
		{
			cur->next = sortHead;
			sortHead = cur;
		}
		else
		{
			ListNode* sortPrev = sortHead;
			ListNode* sortCur = sortHead->next;
			while (sortCur)
			{
				if (cur->val <= sortCur->val)
				{
					sortPrev->next = cur;
					cur->next = sortCur;
					break;
				}
				else
				{
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;
	}
	return sortHead;
}
ListNode* insertionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* cur = head->next;
	ListNode* newHead = head;
	ListNode* Head = NULL;
	newHead->next = NULL;
	while (cur)
	{
		ListNode* next = cur->next;
		//ͷ�壨curС��newHead��
		if (cur->val <= newHead->val)
		{
			cur->next = newHead;
			newHead = cur;
		}
		else
		{
			//cur����newHead
			ListNode* prev = newHead;
			Head = newHead->next;
			while (Head)
			{
				if (Head->val >= cur->val)
				{
					cur->next = Head;
					prev->next = cur;
					break;
				}
				else
				{
					prev = Head;
					Head = Head->next;
				}
			}
			if (Head == NULL)
			{
				prev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;
	}
	return newHead;
}
int main() {
	system("pause");
	return 0;
}
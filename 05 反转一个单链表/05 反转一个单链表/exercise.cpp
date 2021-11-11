#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
};

//打印链表
void SListPrint(ListNode* phead) {
	ListNode* cur = phead;
	while (cur != NULL)
	{
		cout << cur->val << "  ";
		cur = cur->next;
	}
	cout << endl;
}

//尾插
void SListPushBack(ListNode** pphead, int x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		cout << "申请结点失败！" << endl;
		exit(-1);
	}
	newNode->val =	x;
	newNode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//找尾
		ListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//反转单链表：方法1
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
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

//反转单链表：方法2
struct ListNode* reverseList2(struct ListNode* head) {
	struct ListNode* NewNode = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* cur = head, *next = head->next;
	while (cur)
	{
		//头插
		cur->next = NewNode;

		NewNode = cur;
		cur = next;
		if (next)
		{
			next = next->next;
		}
	}
	return NewNode;
}
int main() {
	ListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);

	SListPrint(pList);

	ListNode* cur = reverseList2(pList);
	while (cur != NULL)
	{
		cout << cur->val << "  ";
		cur = cur->next;
	}
	cout << endl;

	system("pause");
	return 0;
}
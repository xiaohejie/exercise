#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
};

//��ӡ����
void SListPrint(ListNode* phead) {
	ListNode* cur = phead;
	while (cur != NULL)
	{
		cout << cur->val << "  ";
		cur = cur->next;
	}
	cout << endl;
}

//β��
void SListPushBack(ListNode** pphead, int x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		cout << "������ʧ�ܣ�" << endl;
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
		//��β
		ListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//��ת����������1
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

//��ת����������2
struct ListNode* reverseList2(struct ListNode* head) {
	struct ListNode* NewNode = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* cur = head, *next = head->next;
	while (cur)
	{
		//ͷ��
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
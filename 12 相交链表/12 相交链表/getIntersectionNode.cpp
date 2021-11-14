#include<iostream>
using namespace std;
/*
	Ïà½»Á´±í
*/
struct ListNode {
public:
	int val;
	struct ListNode* next;
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	int numA = 0, numB = 0;
	while (headA)
	{
		numA++;
		headA = headA->next;
	}
	while (headB)
	{
		numB++;
		headB = headB->next;
	}
	ListNode* longhead = headB;
	ListNode* shorthead = headA;
	if (numA > numB)
	{
		longhead = headA;
		shorthead = headB;
	}
	int k = abs(numA - numB);
	while (k)
	{
		longhead = longhead->next;
		k--;
	}
	while (shorthead)
	{
		if (shorthead->next == longhead->next)
		{
			return shorthead->next;
		}
		shorthead = shorthead->next;
		longhead = longhead->next;
	}
	return NULL;
}
int main() {
	system("pause");
	return 0;
}
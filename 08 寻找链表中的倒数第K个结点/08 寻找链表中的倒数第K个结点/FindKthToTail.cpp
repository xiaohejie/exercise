#include <iostream>
using namespace std;
/*
	输出链表中倒数第K个结点
*/
struct ListNode {
	int val;
	struct ListNode* next;

};

struct ListNode* FindKthTail(struct ListNode* head, int k) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (k)
	{
		fast = fast->next;
		k--;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}
int main() {
	system("pause");
	return 0;
}
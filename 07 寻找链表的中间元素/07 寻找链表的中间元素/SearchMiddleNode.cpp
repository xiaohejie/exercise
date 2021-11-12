#include <iostream>
using namespace std;
/*
	寻找链表的中间元素：
		若为偶数，则返回后一个元素
*/
struct ListNode {
	int val;
	struct ListNode* next;

};
struct ListNode* MiddleNode(struct ListNode* head) {
	struct ListNode* fast = head, * slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
int main() {
	system("pause");
	return 0;
}
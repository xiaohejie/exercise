#include <iostream>
using namespace std;
/*
	Ѱ��������м�Ԫ�أ�
		��Ϊż�����򷵻غ�һ��Ԫ��
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
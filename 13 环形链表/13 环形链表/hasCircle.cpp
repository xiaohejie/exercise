#include<iostream>
using namespace std;
struct ListNode {
public:
	int val;
	struct ListNode* next;
};
bool hasCycle(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	ListNode* fast = head;
	ListNode* slow = head;
	
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
int main() {
	system("pause");
	return 0;
}
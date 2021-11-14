#include "ReserveList.h"
#include "SearchMiddleNode.h"

bool isPalindrome(ListNode* head) {
	//寻找中间元素
	struct ListNode* middleHead = SearchMiddleNode(head);
	//从中间元素开始进行逆置
	struct ListNode* reserveNode = ReserveList(middleHead);
	while (reserveNode)
	{
		if (head->val != reserveNode->val)
		{
			return false;
		}
		else
		{
			head = head->next;
			reserveNode = reserveNode->next;
		}
	}
	return true;
}
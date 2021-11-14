#include "ReserveList.h"
#include "SearchMiddleNode.h"

bool isPalindrome(ListNode* head) {
	//Ѱ���м�Ԫ��
	struct ListNode* middleHead = SearchMiddleNode(head);
	//���м�Ԫ�ؿ�ʼ��������
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
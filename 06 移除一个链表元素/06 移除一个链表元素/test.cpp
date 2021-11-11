#include "deleteVal.h"
int main(){
	struct ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 6;
	struct ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 4;
	struct ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->val = 3;
	struct ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	n4->val = 6;
	struct ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
	n5->val = 6;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	ListNode* head = DeleteVal(n1, 6);


	system("pause");
	return 0;
}
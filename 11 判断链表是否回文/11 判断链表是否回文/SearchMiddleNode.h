#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

struct ListNode* SearchMiddleNode(struct ListNode* head);
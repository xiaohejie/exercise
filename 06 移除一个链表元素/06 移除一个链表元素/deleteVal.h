#pragma once
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
};

//ɾ������Ԫ�صĺ���
struct ListNode* DeleteVal(struct ListNode* lead, int val);

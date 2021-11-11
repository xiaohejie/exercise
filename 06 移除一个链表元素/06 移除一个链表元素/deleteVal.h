#pragma once
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
};

//删除链表元素的函数
struct ListNode* DeleteVal(struct ListNode* lead, int val);

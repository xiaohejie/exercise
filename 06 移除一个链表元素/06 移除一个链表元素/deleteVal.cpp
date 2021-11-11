#include "deleteVal.h"

struct ListNode* DeleteVal(struct ListNode* lead, int val) {
	struct ListNode* cur = lead, * prev = NULL;
	while (cur)
	{
		if (lead->val == val)
		{
			lead = lead->next;
			free(cur);
			cur = lead;
		}
		else {
			if (cur->val != val) {
				prev = cur;
				cur = cur->next;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
	}
	return lead;
}
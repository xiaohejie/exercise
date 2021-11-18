#include <iostream>
using namespace std;
//struct ListNOde {
//public:
//	int val;
//	struct ListNode* next;
//	struct ListNode* random;
//};
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
    Node* cur = head;
    while (cur)
    {
        Node* copy = (Node*)malloc(sizeof(Node));
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val; 

        /*copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;*/
        Node* next = cur->next;
        cur->next = copy;
        copy->next = next;

        cur = next;

    }
    //进行random
    cur = head;
    while (cur)
    {
        Node* copy = cur->next;
        if (cur->random != NULL)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }
        cur = cur->next->next;
    }

    //进行拆解
    cur = head;
    Node* copyHead = head->next; 
    while (cur)
    {
        Node* copy = cur->next;
        Node* next = copy->next;

        cur->next = next;
        if (next)
        {
            copy->next = next->next;
        }
        else {
            copy->next = NULL;
        }
        cur = next;
    }
    return copyHead;
}
int main() {
	system("pause");
	return 0;
}
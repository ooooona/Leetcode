#include <iostream>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = NULL;
		ListNode* fast = NULL;
		fast = slow = head;

		while (1)
		{
			if (slow == NULL || fast == NULL)
			{
				return NULL;
			}
			slow = slow->next; fast = fast->next;
			if (fast == NULL)
			{
				return NULL;
			}
			fast = fast->next;
			if (fast == slow)
			{
				break;
			}
		}

		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main()
{
	return 0;
}
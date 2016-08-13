#include <iostream>
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
	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;

		do
		{
			if (fast == NULL || slow == NULL)
			{
				return false;
			}
			fast = fast->next;
			slow = slow->next;
			if (fast == NULL)
			{
				return false;
			}
			fast = fast->next;
		} while (fast != slow);
		return true;
	}
};

int main()
{
	return 0;
}
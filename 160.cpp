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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int m = 0, n = 0;
		for (ListNode* p = headA; p != NULL; p = p->next)
		{
			m++;
		}
		for (ListNode* q = headB; q != NULL; q = q->next)
		{
			n++;
		}
		if (m > n)
		{
			int delta = m - n;			
			while (delta--)
			{
				headA = headA->next;
			}			
		}
		else
		{
			int delta = n - m;
			while (delta--)
			{
				headB = headB->next;
			}
		}

		while (headA && headB)
		{
			if (headA == headB)
			{
				return headA;
			}
			else
			{
				headA = headA->next;
				headB = headB->next;
			}
		}
		return NULL;
	}
};

int main()
{

	return 0;
}
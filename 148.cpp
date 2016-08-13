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
	ListNode* sortList(ListNode* head) {
		return this->sortList(head, NULL);
	}
private:
	ListNode* sortList(ListNode* head, ListNode* tail)
	{
		if (head == tail) return head;
		ListNode *preHead = NULL, *prePt = NULL;
		ListNode *postHead = NULL, *postPt = NULL;
		ListNode *p = head->next;
		while (p != tail)
		{
			ListNode* tmp = p->next;
			if (p->val < head->val)
			{
				p->next = head;
				if (preHead == NULL)
				{
					prePt = preHead = p;
				}
				else
				{
					prePt->next = p;
					prePt = prePt->next;
				}
			}
			else
			{
				p->next = NULL;
				if (postHead == NULL)
				{
					postPt = postHead = p;
				}
				else
				{
					postPt->next = p;
					postPt = postPt->next;
				}
			}
			p = tmp;
		}
		head->next = postHead;
		p = preHead;
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
		system("pause");
		ListNode* ansHead = this->sortList(preHead, prePt);
		this->sortList(postHead, postPt);
		return ansHead;
	}
};

int main()
{
	ListNode *p1 = new ListNode(4), *p2 = new ListNode(-1), *p3 = new ListNode(3), *p4 = new ListNode(-7);
	p1->next = p2, p2->next = p3, p3->next = p4;
	Solution sol;
	ListNode* np = sol.sortList(p1);
	for (ListNode* p = np; p != NULL; p = p->next)
	{
		cout << p->val << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
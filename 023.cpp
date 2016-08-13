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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (n == 0)
		{
			return NULL;
		}
		else if (n == 1)
		{
			return lists[0];
		}
		else if (n == 2)
		{
			return this->merge2OrderedList(lists[0], lists[1]);
		}
		else	{
			vector<ListNode*> list1;
			for (int i = 0; i < (n >> 1); ++i)
			{
				list1.push_back(lists[i]);
			}
			vector<ListNode*> list2;
			for (int i = (n >> 1); i < n; ++i)
			{
				list2.push_back(lists[i]);
			}
			ListNode* head1 = this->mergeKLists(list1);
			ListNode* head2 = this->mergeKLists(list2);

			return this->merge2OrderedList(head1, head2);
		}
	}
private:
	ListNode* merge2OrderedList(ListNode* head1, ListNode* head2)
	{
		ListNode* head = NULL;
		ListNode* cur = NULL;
		while (head1 != NULL && head2 != NULL)
		{
			if (head1->val < head2->val)
			{
				if (head == NULL)
				{
					head = head1;
				}
				else
				{
					cur->next = head1;
				}
				cur = head1;
				head1 = head1->next;
			}
			else
			{
				if (head == NULL)
				{
					head = head2;
				}
				else
				{
					cur->next = head2;
				}
				cur = head2;
				head2 = head2->next;
			}
		}
		while (head1 != NULL)
		{
			if (head == NULL)
			{
				head = head1;
			}
			else
			{
				cur->next = head1;
			}
			cur = head1;
			head1 = head1->next;
		}
		while (head2 != NULL)
		{
			if (head == NULL)
			{
				head = head2;
			}
			else
			{
				cur->next = head2;
			}
			cur = head2;
			head2 = head2->next;
		}
		return head;
	}
};

int main()
{
	system("pause");
	return 0;
}
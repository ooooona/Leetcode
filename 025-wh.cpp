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
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (head == NULL)
			return head;
		size = getSize(head);
		if (k > size)
			return head;
		virtualHead = new ListNode(0);
		virtualHead->next = head;
		int iterCnt = size / k;
		ListNode* oshiri = virtualHead;
		ListNode* startNode = head;
		for (int i = 0; i < iterCnt; i++)
		{
			oshiri = doOneK(oshiri, startNode, k);
		}
		return virtualHead->next;
	}
	ListNode* doOneK(ListNode* oshiri, ListNode*& head, int k)
	{
		//return the lastNode
		ListNode* crt, *victim, *new_oshiri;
		crt = findFirstCrt(head, k);
		new_oshiri = head;
		victim = head;
		for (int i = 0; i < k; i++)
		{
			link(victim, crt);
		}
		oshiri->next = crt;
		head = victim;
		return new_oshiri;
	}

	ListNode* virtualHead;
	int size;
	void link(ListNode*& victim, ListNode*& crt)
	{
		ListNode* tmp = victim->next;
		victim->next = crt;
		crt = victim;
		victim = tmp;
	}

	int getSize(ListNode* head)
	{
		int cnt = 0;
		ListNode* p = head;
		while (p)
		{
			cnt++;
			p = p->next;
		}
		return cnt;
	}

	ListNode* findFirstCrt(ListNode* head, int k)
	{
		ListNode* crt = head;
		for (size_t i = 0; i < k; i++)
		{
			crt = crt->next;
		}
		return crt;
	}
};


ListNode* testData(int n)
{
	ListNode* head = new ListNode(1);
	ListNode* crt = head;
	for (int i = 2; i <= n; i++)
	{
		ListNode* tmp = new ListNode(i);
		crt->next = tmp;
		crt = tmp;
	}
	return head;
}

void print(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	ListNode* head = testData(10);
	print(head);
	Solution slu;
	ListNode* newHead = slu.reverseKGroup(head, 12);
	print(newHead);

	system("pause");
	return 0;
}
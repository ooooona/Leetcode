#include <iostream>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list with a random pointer.
*/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		///01.copy
		RandomListNode* Pt = head;
		RandomListNode* nextPt = Pt->next;
		while(1)
		{
			RandomListNode* tmpPt = new RandomListNode(Pt->label);
			Pt->next = tmpPt; tmpPt->next = nextPt;
			Pt = nextPt;
			if (Pt == NULL)
			{
				break;
			}
			nextPt = nextPt->next;
		}
		///02.copy2
		Pt = head;
		nextPt = Pt->next;
		while(1)
		{
			RandomListNode* randomNextPt = NULL;
			RandomListNode* randomPt = Pt->random;
			if (randomPt != NULL)
			{
				randomNextPt = randomPt->next;
			}
			nextPt->random = randomNextPt;
			Pt = Pt->next->next;
			if (Pt == NULL)
			{
				break;
			}
			nextPt = nextPt->next->next;
		}
		///03.
		Pt = head;
		nextPt = Pt->next;
		RandomListNode* nhead = nextPt;
		while(1)
		{
			Pt->next = nextPt->next; Pt = Pt->next;
			if (Pt == NULL)
			{
				break;
			}
			nextPt->next = Pt->next; nextPt = nextPt->next;
		}
		return nhead;
	}
};

int main()
{
	return 0;
}
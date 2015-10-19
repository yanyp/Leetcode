#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* reverse(ListNode* node)
	{
		ListNode* head;
		if(node->next == NULL)
			head = node;
		else
		{
			head = reverse(node->next);
			node->next->next = node;
		}
		return head;
	}
};

int main()
{
	int num = 40;
	ListNode *head_old = new ListNode(0);
	ListNode *p = head_old;
	for(int i = 0; i < num; i++)
	{
		p->next = new ListNode(i);
		p = p->next;
		cout << p->val << ' ';
	}
	cout << endl;
	
	Solution excalibur;
	ListNode *head_new= excalibur.reverse(head_old);
	head_old->next = NULL;
	ListNode *q = head_new;
	while(1)
	{
		if(q->next == NULL)
			break;
		else
		{
			cout << q->val << ' ';
			q = q->next;
		}
	}
	cout << endl << "Reverse End" << endl;
	
	return 0;
}
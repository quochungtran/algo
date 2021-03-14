/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int len = length(head);
        ListNode *firstHalf = head;
        ListNode *secondHalf;

        for (int i = 0; i < len / 2; i++)
        {
            head = head->next;
        }
        if (len % 2 != 0)
            head = head->next;

        for (int i = 0; i < len / 2; i++)
        {
            insertList(&secondHalf, head->val);
            head = head->next;
        }
        // printList(secondHalf);
        for (int i = 0; i < len / 2; i++)
        {

            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }

    void insertList(ListNode **head, int x)
    {
        ListNode *p;

        p = new ListNode();
        p->val = x;
        p->next = *head;
        *head = p;
    }
    int length(ListNode *head)
    {
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }

        return count;
    }

    // print List
    void printList(ListNode *head)
    {
        ListNode *l = head;

        while (l != NULL)
        {
            std::cout << l->val << " ";
            l = l->next;
        }
    }
};
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *ans = new ListNode();

        // precedent ode of the last node
        ListNode *pred;
        ListNode *an = ans;

        int carry = 0;
        int push = 0;

        // a and b is the two digits of each node
        int a = 0, b = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int valNode;

            if (l1 == nullptr)
                a = 0;
            else
                a = l1->val;

            if (l2 == nullptr)
                b = 0;
            else
                b = l2->val;

            // push operation
            push = a + b + carry;

            an->val = (push) % 10;

            // recalcule the carry
            if (push >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            // traverse through of two vectors
            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;

            an->next = new ListNode();
            pred = an;
            an = an->next;
        }

        // handle the last node
        if (carry == 1)
        {
            an->val = 1;
        }

        if (an->val == 0 && an != nullptr)
        {
            pred->next = nullptr;
        }

        return ans;
    }
};

// Complexity = O(n)
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head != nullptr && head->next == nullptr)
            return head;

        ListNode *list = head;
        while (list != nullptr && list->next != nullptr)
        {
            swapValeur(list, list->next);
            list = list->next->next;
        }
        return head;
    }

    void swapValeur(ListNode *l1, ListNode *l2)
    {
        int temp;
        temp = l1->val;
        l1->val = l2->val;
        l2->val = temp;
    }
};
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
    ListNode *partition(ListNode *head, int x)
    {

        ListNode *headMain = head;

        while (true)
        {
            ListNode *node = findFirstNodeGreater(head, x);

            ListNode *nodeLess = node;
            while (nodeLess != nullptr && nodeLess->val >= x)
            {
                nodeLess = nodeLess->next;
            }

            if (nodeLess == nullptr)
            {
                return headMain;
            }

            ListNode *predNodeLess = predNode(head, nodeLess);
            predNodeLess->next = nodeLess->next;

            if (predNode(headMain, node) != nullptr)
            {
                head = predNode(headMain, node);
                nodeLess->next = head->next;
                head->next = nodeLess;
            }
            else
            {
                nodeLess->next = headMain;
                headMain = nodeLess;
            }
        }

        return headMain;
    }

    ListNode *findFirstNodeGreater(ListNode *head, int x)
    {
        while (head != nullptr && head->val < x)
        {
            head = head->next;
        }

        return head;
    }

    ListNode *predNode(ListNode *head, ListNode *node)
    {
        ListNode *head1 = head;

        if (head1 == nullptr || head1->next == nullptr)
        {
            return nullptr;
        }

        if (head->next == node)
        {
            return head;
        }
        else
        {
            return predNode(head->next, node);
        }
    }
};
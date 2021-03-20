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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
     
    ListNode* headMain = head;
        
     while(head!=nullptr)
     {
        ListNode * node = findNote(head, x);
    
        ListNode* nodeLess = node;
        while(nodeLess != nullptr && nodeLess->val >= x)
        {
            nodeLess = nodeLess->next;
        }
        
        if ( x <= nodeLess->val)
        {
             PredNodeLess->next = NodeLess->next;
             nodeLess->next = head->next;
             head->next = nodeLess;
        }
        else 
        {
            return headMain;
        }
         
         head = head->next ;
        
       }
        
        return headMain;
    }
    
    ListNode* findNote(ListNode* head, int x){
        while (head != nullptr && head->val >= x){
            head = head -> next;
        }
        
        return head;
    }
};
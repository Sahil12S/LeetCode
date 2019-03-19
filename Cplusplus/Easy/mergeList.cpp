/**
 * Merge 2 sorted linked list and return it as a new list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *prev = p1;
        ListNode *temp = p2;
        
	// Case for empty linked lists.
        if (!p1)
            return l2;
        if (!p2)
            return l1;
        
	// Loop through both lists and keep inserting elements from l2 into l1.
        while (p1) {
            if (p1->val <= p2->val) {
                prev = p1;
                p1 = p1->next;
            }
            else {
                temp = p2;
                p2 = p2->next;
                
                if (p1 == prev) {
                    prev = temp;
                    l1 = prev;
                }
                else {
                    prev->next = temp;
                    prev = prev->next;
                }
                
                prev->next = p1;
                
                if(!p2)
                    break;
            }
        }
        
	// Add remaining elements of l2 at the end of l1.
        if (p2 != nullptr) {
            prev->next = p2;
        }
        
        return l1;
    }
};

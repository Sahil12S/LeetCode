/**
 * Find the node at which intersection of 2 lists begin.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = findLength(headA);
        int lengthB = findLength(headB);
        int d;
        
        ListNode *p1 = nullptr;
        ListNode *p2 = nullptr;
        
	// Find difference between both linked lists.
        if (lengthA > lengthB) {
            d = lengthA - lengthB;
            p1 = headA;
            p2 = headB;
            
        } else {
            d = lengthB - lengthA;
            p1 = headB;
            p2 = headA;
        }
        
	// Move head of longer linked list
        while (d > 0) {
            p1 = p1 -> next;
            d--;
        }
        
	// Find if at any point both have a common node.
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            
            if (p1 == nullptr)
                return nullptr;
        }
        
        return p1;
        
    }
    

    /**
     * Function to find the length of linked list.
     * @param head: pointer to the head of linked list.
     * @return: length of linked list.
     */ 
    int findLength(ListNode *head) {
        int count = 0;
        ListNode *current = head;
        while(current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

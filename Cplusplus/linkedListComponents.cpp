// We are given head, the head node of a linked list containing unique integer values.
// We are also given the list G, a subset of the values in the linked list.
// Return the number of connected components in G,
// where two values are connected if they appear consecutively in the linked list.

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
    int numComponents(ListNode* head, vector<int>& G) {
        // sort(G.begin(), G.end());
        vector<int> Gv(10000, -1);
        
        for( int n : G)
        {
            Gv[n] = 1;
        }
        
        ListNode* dummy = head;
        
        int i = 0;
        
        // cout << "head->next->val" << endl;
        // int length = 0;
        bool continuous = false;
        int count = 0;
        while(dummy) {
            if (Gv[dummy->val] > 0)
            {
                // cout << Gv[dummy->val] << endl;
                continuous = true;
            }
            else if (continuous)
            {
                count++;
                continuous = false;
            }
            dummy = dummy->next;
        }
        if (continuous) {
            count++;
        }
        return count;
    }
};
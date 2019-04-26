/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
struct Compare {
    bool operator() ( ListNode* l1, ListNode* l2 ) {
        return l1->val > l2->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        ListNode* last;
        priority_queue< ListNode*, vector< ListNode* >, Compare > pq;
        
        for ( auto list : lists )
        {
            if( list != nullptr )
            {
                pq.push( list );
                
            }
        }
        
        while ( !pq.empty() )
        {
            ListNode* top = pq.top();
            pq.pop();
            
            if ( top->next != nullptr )
            {
                pq.push( top->next );
            }
            
            if ( result == nullptr )
            {
                result = top;
                last = top;
            }
            else
            {
                last->next = top;
                last = top;
            }
  
        }
        
        return result;
        
    }
};
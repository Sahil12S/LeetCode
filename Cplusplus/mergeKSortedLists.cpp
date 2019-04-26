// USING MIN HEAP

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



// USING DIVIDE AND CONQUER

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
ListNode* merge( ListNode* l1, ListNode* l2 )
{
    ListNode* result = nullptr;
    if ( l1 == nullptr )
    {
        return l2;
    }
    else if ( l2 == nullptr )
    {
        return l1;
    }
    
    if ( l1->val <= l2->val )
    {
        
        result = l1;
        result->next = merge( l1->next, l2 );
    }
    else
    {
        result = l2;
        result->next = merge( l1, l2->next );
    }
    
    return result;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.size() == 0 )
        {
            return nullptr;
        }
        int last = lists.size() - 1;
        
        while ( last != 0 )
        {
            int i = 0;
            int j = last;
            
            while ( i < j )
            {
                lists[i] = merge( lists[i], lists[j] );
                i++, j--;
                
                if ( i >= j )
                {
                    last = j;
                }
            }
            
        }
        
        return lists[0];
        
    }
};
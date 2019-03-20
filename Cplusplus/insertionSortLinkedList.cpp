// Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head)
    {
        auto curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        // prev = curr;
        // prev->next = nullptr;
        // curr = curr->next;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* start = nullptr;
        
        ListNode* curr = head;
        while (curr != nullptr)
        {
            if (start == nullptr)
            {
                start = head;
                curr = curr->next;
                start->next = nullptr;
            }
            else if (curr->val >= start->val)
            {
                auto temp = curr->next;
                curr->next = start;
                start = curr;
                curr = temp;
            }
            else
            {
                auto itr = start;
                while (itr->next && itr->next->val > curr->val)
                {
                    itr = itr->next;
                }
                auto tempItr = itr->next;
                itr->next = curr;
                itr = itr->next;
                curr = curr->next;
                itr->next = tempItr;
            }
        }
        
        head = reverse(start);
        return head;
    }
};
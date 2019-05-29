/**
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 */

#include <algorithm>
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
    ListNode *node;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        node = head;
        std::srand(time(nullptr));
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *curr = node;
        int len = 1;
        int res;

        while (curr)
        {
            if (rand() % len == 0)
            {
                res = curr->val;
            }
            len++;
            curr = curr->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
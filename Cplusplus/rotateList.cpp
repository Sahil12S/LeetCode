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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int len = 0; // Length of linked list
        auto curr = head;
        ListNode* tail = new ListNode(0);
        tail->next = head;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
            tail = tail->next;
        }
        if (k % len == 0)
        {
            return head;
        }
        int idx = len - k % len;

        curr = head;
        while (idx > 1)
        {
            curr = curr->next;
            idx--;
        }

        auto temp = curr->next;
        curr->next = nullptr;

        tail->next = head;
        head = temp;
        return head;
    }
};
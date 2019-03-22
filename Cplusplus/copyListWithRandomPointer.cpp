// A linked list is given such that each node contains an additional
//  random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* curr = head;
        
        while (curr != nullptr)
        {
            // cout << curr->val << endl;
            Node* temp = new Node(curr->val, curr->next, nullptr);
            curr->next = temp;
            curr = curr->next->next;
        }
        
        curr = head;
        
        Node* newHead = curr->next;
        Node* curr2 = newHead;
        while (curr != nullptr)
        {
            curr->next->random = curr->random != nullptr ? curr->random->next : nullptr;
            curr = curr->next->next;
            // if (curr != nullptr)
            // {
            //     curr2 = curr->next;
            // }
        }
        
        
        curr = head;
        while (curr != nullptr)// && curr2->next != nullptr)
        {
            curr->next = curr->next->next;
            curr = curr->next;
            if (curr == nullptr)
            {
                curr2->next = nullptr;
            }
            else
            {
                curr2->next = curr2->next->next;
                curr2 = curr2->next;
            }
        }
        // curr = head;
        // while (curr != nullptr)
        // {
        //     cout << curr->val << ", ";
        //     cout << (curr->next != nullptr ? curr->next->val : -1) << ", ";
        //     cout << (curr->random != nullptr ? curr->random->val : -1) << endl;
        //     curr = curr->next;
        // }
        
        
        return newHead;
    }
};
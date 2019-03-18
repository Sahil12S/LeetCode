// Sort Linked List

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* sort(ListNode* head);
void splitList(ListNode* source, ListNode** first, ListNode** second);
ListNode* merge(ListNode* first, ListNode*  second);
void printList(ListNode* head);

void push(ListNode** head, int val);

int main(int argc, char const *argv[])
{
    ListNode* res;
    ListNode* a;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    push(&a, 7);

    a = sort(a);
    printList(a);
    return 0;
}

ListNode* sort(ListNode* head)
{
    ListNode* first = nullptr;
    ListNode* second = nullptr;
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    splitList(head, &first, &second);

    first = sort(first);
    second = sort(second);

    return merge(first, second);
}

void splitList(ListNode* source, ListNode** first, ListNode** second)
{
    ListNode* slow = source;
    ListNode* fast = source->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = source;
    *second = slow->next;
    
    slow->next = nullptr;
}

ListNode* merge(ListNode* first, ListNode* second)
{
    ListNode* result = nullptr;

    if (first == nullptr)
    {
        return second;
    }
    else if (second == nullptr)
    {
        return first;
    }

    if (first->val <= second->val)
    {
        result = first;
        result->next = merge(first->next, second);
    }
    else
    {
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
}

void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void push(ListNode** head, int val)
{
    ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = *head;
    *head = node;
    // auto temp = *head;
    // cout << temp->val << endl;
}
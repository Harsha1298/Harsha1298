// Problem Statement
// Given a singly linked list A and an integer B, 
// reverse the nodes of the list B at a time and return the modified linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* prev = NULL;
    ListNode* current = A;
    ListNode* next = NULL;
    int count = 0;
    ListNode* temp = A;
    while (temp && count < B) {
        temp = temp->next;
        count++;
    }
    if (count == B) {
        while (current != NULL && count > 0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count--;
        }
        if (next != NULL) {
            A->next = reverseList(next, B);
        }
        return prev;
    }
    return A;
}

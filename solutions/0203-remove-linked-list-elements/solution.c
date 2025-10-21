/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node before head to handle edge cases
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            // Skip the node with the target value
            prev->next = curr->next;
        } else {
            // Move prev forward only when we don't delete
            prev = curr;
        }
        curr = curr->next;
    }

    // Return the updated list head
    return dummy.next;
}


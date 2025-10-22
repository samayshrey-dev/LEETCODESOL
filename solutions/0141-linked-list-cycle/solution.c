/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL)
        return false;  // Empty or single-node list can't form a cycle

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2

        if (slow == fast)
            return true;             // Cycle detected
    }

    return false; // If fast reaches end → no cycle
}


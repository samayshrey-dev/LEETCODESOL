/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;  

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;
    struct ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* first = head;
    struct ListNode* second = prev;  
    bool palindrome = true;
    while (second != NULL) {
        if (first->val != second->val) {
            palindrome = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    return palindrome;
}


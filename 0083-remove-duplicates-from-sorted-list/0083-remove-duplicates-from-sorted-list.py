class Solution:
    def deleteDuplicates(self, head):
        # Edge case: empty list
        if not head:
            return None
        
        current = head
        
        # Single pass traversal
        while current.next:
            if current.val == current.next.val:
                # Skip duplicate node
                current.next = current.next.next
            else:
                # Move to next unique node
                current = current.next
        
        return head
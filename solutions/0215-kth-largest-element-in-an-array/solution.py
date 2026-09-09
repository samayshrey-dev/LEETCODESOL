import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        # 1. Initialize a min-heap with the first k elements
        heap = nums[:k]
        heapq.heapify(heap)
        
        # 2. Iterate through the rest of the array
        for num in nums[k:]:
            # If current number is larger than the heap's minimum,
            # it belongs in the top K largest elements
            if num > heap[0]:
                heapq.heapreplace(heap, num)
                
        # 3. The root of the min-heap is now the kth largest element
        return heap[0]

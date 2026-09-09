class Solution:
    def check(self, nums):
        count_drops = 0
        n = len(nums)

        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                count_drops += 1

        return count_drops <= 1

class Solution(object):
    def removeDuplicates(self, nums):
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] == nums[i + 1]:
                nums.pop(i + 1)

        return len(nums)

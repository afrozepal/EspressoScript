class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        k=[]
        for i in range (0,len(nums)):
            for j in range((i+1),len(nums)):
                if nums[i]+nums[j]==target:
                    k.append(i,j)
                    k.append(j)
                    return k
        
        
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.
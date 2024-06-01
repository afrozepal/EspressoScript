class Solution(object):
    def singleNumber(self, nums):

        visited=set()
        ans=[]
        for x in nums:
            if x in visited:
                if x in ans:
                    ans.remove(x)
            else:
                ans.append(x)
                visited.add(x)
        return ans
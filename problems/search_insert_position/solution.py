class Solution(object):
    def searchInsert(self, nums, target):
        j=[]
        for i in nums:
            if i<target:
                j.append(i)
        return len(j)     
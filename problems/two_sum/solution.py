class Solution:
    def twoSum(self,nums,target):
        i = 0
        while i < len(nums):
            a= nums[i]
            o = 0
            while o < len(nums):
                b = nums[o]
                if i == o:
                    o+=1
                    continue
                else:
                    val = a+b
                    if val == target:
                        return [i,o]
                        o+=1
                    else:
                        o+=1
            i+=1
        return


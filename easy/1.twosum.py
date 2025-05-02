class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for key,value in enumerate(nums):
            dict={}
            complemento = target-value
            if complemento in dict:
                return [dict[complemento],key]
            dict[value]=key
        return []
            
            

obj=Solution()
nums=[2,7,11,15]
obj.twoSum(nums,9)


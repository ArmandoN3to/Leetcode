class Solution(object):
    def containsDuplicate(self, nums):
        setnums = set()         # create a empty set
        for num in nums:
            if num in setnums:
                return 1
            setnums.add(num)    
        return 0



        
    



        
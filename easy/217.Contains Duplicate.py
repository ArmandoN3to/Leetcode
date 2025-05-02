class Solution(object):
    def containsDuplicate(self, nums):
        setnums = set()         # create a empty set
        for num in nums:
            if num in setnums:
                return True
            setnums.add(num)    
        return False



        
    



        
class Solution(object):
    def isAnagram(self, s, t):
        if len(s) == len(t):
            if sorted(s) == sorted(t):
                return True
        else:
            return False
 
s= "anagram"      
t="nagaram" 
obj=Solution()
obj.isAnagramcount(s,t)
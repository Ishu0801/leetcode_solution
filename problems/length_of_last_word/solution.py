class Solution(object):
    def lengthOfLastWord(self, s):
        return len(str(s).split()[-1])
        
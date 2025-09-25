class Solution(object):
    def isPalindrome(self, x):
        a = str(x)
        b = a[::-1]
        if x>=0:
            c = int(b)
            if x == c:
                return True
            else:
                return False
        else:
            return False
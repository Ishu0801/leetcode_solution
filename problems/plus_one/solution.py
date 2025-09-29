class Solution(object):
    def plusOne(self, digits):
        cl=[]
        es=""
        for el in digits:
            es+=str(el)
        r = str(int(es)+1)
        for x in r:
            cl.append(int(x))
        return cl
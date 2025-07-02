class Solution(object):
    def divisibilityArray(self, word, m):
        ans = []
        curr = 0
        for a in word :
            curr = curr*10 + int(a)
            print(curr)
        return ans
        
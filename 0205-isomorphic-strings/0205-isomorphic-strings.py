class Solution(object):
    def isIsomorphic(self, s, t):
        a = [-1] * 256
        b = [-1] * 256

        for i in range(len(s)):
            x = ord(s[i])
            y = ord(t[i])

            if a[x] != -1 and a[x] != y:
                return False

            if b[y] != -1 and b[y] != x:
                return False

            a[x] = y
            b[y] = x

        return True
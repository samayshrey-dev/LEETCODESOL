class Solution(object):
    def isPalindrome(self, s):
        s = s.lower()
        clean = ""

        for ch in s:
            if ch.isalnum():
                clean += ch

        rev = ''.join(reversed(clean))

        if rev == clean:
            return True
        else:
            return False
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""

        def expand_around_center(left, right):
            # Expand outwards as long as characters match and indices are valid
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the palindrome substring
            return s[left + 1:right]

        longest = ""
        for i in range(len(s)):
            # Case 1: Odd length palindromes (centered at i)
            p1 = expand_around_center(i, i)
            # Case 2: Even length palindromes (centered between i and i+1)
            p2 = expand_around_center(i, i + 1)
            
            # Update the longest found so far
            if len(p1) > len(longest):
                longest = p1
            if len(p2) > len(longest):
                longest = p2
                
        return longest

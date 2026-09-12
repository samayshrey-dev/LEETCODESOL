class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # Negative numbers are not palindromes (e.g., -121 != 121-)
        if x < 0:
            return False
        
        original = x
        reversed_num = 0
        
        # Build the reversed number mathematically
        while x > 0:
            # Get the last digit
            digit = x % 10
            # Append it to the reversed number
            reversed_num = reversed_num * 10 + digit
            # Remove the last digit from x
            x //= 10
            
        return original == reversed_num

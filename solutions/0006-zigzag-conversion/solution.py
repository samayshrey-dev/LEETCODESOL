class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # Edge case: if only one row or string is shorter than rows, no change
        if numRows == 1 or numRows >= len(s):
            return s

        # Create a list of strings for each row
        rows = [''] * numRows
        index = 0
        step = 1

        for char in s:
            rows[index] += char
            
            # Change direction if we hit the top or bottom row
            if index == 0:
                step = 1
            elif index == numRows - 1:
                step = -1
            
            index += step

        return ''.join(rows)

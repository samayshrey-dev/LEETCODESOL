class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        for ch in ransomNote:
            if ch in magazine:
                magazine = magazine.replace(ch, "", 1)
            else:
                return False

        return True
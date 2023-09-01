class Solution:
    def isVowel(self, ch: str):
        return ch in ['a', 'e', 'i', 'o', 'u']

    def maxVowels(self, s: str, k: int) -> int:
        count = 0
        for i in range(k):
            count += int(self.isVowel(s[i]))
        max_count = count
        if k < len(s):
            for i in range(k, len(s)):
                count = count - int(self.isVowel(s[i-k])) + int(self.isVowel(s[i]))
                max_count = max(max_count, count)
        return max_count
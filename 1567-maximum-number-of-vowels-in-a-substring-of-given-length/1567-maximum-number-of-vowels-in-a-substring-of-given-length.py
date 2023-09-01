class Solution:
    def isVowel(self, ch: str):
        return 1 if ch in 'aeiou' else 0

    def maxVowels(self, s: str, k: int) -> int:
        count = 0
        for i in range(k):
            count += self.isVowel(s[i])
        max_count = count
        if (k < len(s)) and (max_count<k):
            for i in range(k, len(s)):
                count = count - self.isVowel(s[i-k]) + self.isVowel(s[i])
                max_count = max(max_count, count)
        return max_count
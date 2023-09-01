class Solution:

    def isVowel(self, ch: str):
        return 1 if ch in 'aeiou' else 0

    def maxVowels(self, s: str, k: int) -> int:
        count = 0
        for i in range(k):
            count += self.isVowel(s[i])
        max_count = count
        if (k < len(s)):
            for i in range(k, len(s)):
                if self.isVowel(s[i-k]):
                    count -=1
                if self.isVowel(s[i]):
                    count += 1 
                max_count = max(max_count, count)
        return max_count
class Solution:
    def isVowel(self, ch: str):
        return ch in ['a', 'e', 'i', 'o', 'u']

    def maxVowels(self, s: str, k: int) -> int:
        count = max_count = 0
        for i in range(len(s)):
            if i < k:
                count += int(self.isVowel(s[i]))
                if i == k-1:
                    max_count = count
            else:
                count = count - int(self.isVowel(s[i-k])) + int(self.isVowel(s[i]))
                max_count = max(max_count, count)
        return max_count
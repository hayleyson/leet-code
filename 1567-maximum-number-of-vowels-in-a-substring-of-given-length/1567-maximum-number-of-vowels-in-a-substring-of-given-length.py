class Solution:

    def maxVowels(self, s: str, k: int) -> int:
        isVowels = [ch in 'aeiou' for ch in s]
        maxCount = count = sum(isVowels[:k])
        if (maxCount == k) or (len(s) == k):
            return maxCount
        for i in range(k, len(s)):
            if isVowels[i]:
                count +=1
            if isVowels[i-k]:
                count -= 1
            maxCount = max(maxCount, count)
            if maxCount == k:
                return maxCount
        return maxCount

    # def isVowel(self, ch: str):
    #     return 1 if ch in 'aeiou' else 0

    # def maxVowels(self, s: str, k: int) -> int:
    #     count = 0
    #     for i in range(k):
    #         count += self.isVowel(s[i])
    #     max_count = count
    #     if (k < len(s)):
    #         for i in range(k, len(s)):
    #             count = count - self.isVowel(s[i-k]) + self.isVowel(s[i])
    #             max_count = max(max_count, count)
    #     return max_count
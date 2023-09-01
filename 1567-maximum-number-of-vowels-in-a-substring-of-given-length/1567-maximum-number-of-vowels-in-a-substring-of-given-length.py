class Solution:

    def maxVowels(self, s: str, k: int) -> int:
        ## because list comprehension is faster?
        # isVowels = [1 if ch in 'aeiou' else 0 for ch in s] 
        isVowels=[]
        for ch in s:
            isVowels.append(1 if ch in 'aeiou' else 0)

        maxCount = count = sum(isVowels[:k])
        if (maxCount == k) or (len(s) == k):
            return maxCount
        for i in range(k, len(s)):
            # if isVowels[i] == 1:
            #     count +=1
            # if isVowels[i-k] == 1:
            #     count -= 1
            count = count + isVowels[i] - isVowels[i-k] 
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
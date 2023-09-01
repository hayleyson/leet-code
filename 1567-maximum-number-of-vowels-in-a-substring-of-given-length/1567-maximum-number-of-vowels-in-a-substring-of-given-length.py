class Solution:
    def maxVowels(self, s: str, k: int) -> int:

        count = 0
        for i in range(k):
            count += 1 if s[i] in 'aeiou' else 0
        max_count = count
        if (len(s)==k) or (max_count==k):
            return max_count
        for i in range(k, len(s)):
            # if then count -=1 or +=1 is faster!
            if s[i-k] in 'aeiou':
                count -=1
            if s[i] in 'aeiou':
                count += 1 
            # below is slower.
            # count = count - int(s[i-k] in 'aeiou') + int(s[i] in 'aeiou)
            max_count = max(max_count, count)
            if (max_count==k):
                return max_count
        return max_count
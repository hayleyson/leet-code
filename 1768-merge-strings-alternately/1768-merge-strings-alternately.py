class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        # res = ''
        # len1 = len(word1)
        # len2 = len(word2)
        # minlen = min(len1, len2)

        # for i in range(minlen):
        #     res += word1[i]
        #     res += word2[i]
        # if len1 > len2:
        #     res += word1[i+1:]
        # elif len2 > len1:
        #     res += word2[i+1:]

        # return res

        # check which one is shorter
        res = ''
        i, j = 0, 0
        while i < len(word1):
            res += word1[i]
            i += 1
            while j < len(word2):
                res += word2[j]
                j += 1
                break
        if j < len(word2):
            res += word2[j:]

        return res
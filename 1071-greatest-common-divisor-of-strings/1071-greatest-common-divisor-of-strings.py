class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        cand = ''
        for i, ch in enumerate(str1):
            if (i < len(str2)) and (str2[i] == ch):
                cand += ch
            else:
                break
        str_criterion = str1 if len(str1) > len(str2) else str2
        while len(cand) > 0:
            j = 0
            while str1[j:j+len(cand)] == cand:
                j += len(cand)
            k = 0
            while str2[k:k+len(cand)] == cand:
                k += len(cand)
            if (j == len(str1)) and (k == len(str2)):
                return cand
            else: 
                cand = cand[:-1]
        return ''

        


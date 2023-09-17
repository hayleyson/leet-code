class Solution:
    
    def gcdOfNumbers(self, num1: int, num2: int) -> int:
        minNum = min(num1, num2)
        for i in range(1, minNum +1):
            if (num1 % i ==0) and (num2 % i ==0):
                cd = i
        return cd
    
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcdLen = self.gcdOfNumbers(len(str1), len(str2))
        gcdCand = str1[:gcdLen]
        for i in range(0, len(str2), gcdLen):
            if str2[i:i+gcdLen] != gcdCand:
                return ""
        for i in range(0, len(str1), gcdLen):
            if str1[i:i+gcdLen] != gcdCand:
                return ""
        return gcdCand
            
            
class Solution:
    
    def gcdOfNumbers(self, num1: int, num2: int) -> int:
        minNum = min(num1, num2)
        for i in range(1, minNum +1):
            if (num1 % i ==0) and (num2 % i ==0):
                cd = i
        return cd
    
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcdLen = self.gcdOfNumbers(len(str1), len(str2))
        if (str1[:gcdLen] != str2[:gcdLen]):
            return ""
        else:
            gcdCand = str1[:gcdLen]
            str1Divisible, str2Divisible =True, True
            for i in range(0, len(str1), gcdLen):
                if str1[i:i+gcdLen] != gcdCand:
                    str1Divisible=False
                    break
            for i in range(0, len(str2), gcdLen):
                if str2[i:i+gcdLen] != gcdCand:
                    str2Divisible=False
                    break
            if str1Divisible and str2Divisible:
                return gcdCand
            else:
                return ""
            

        


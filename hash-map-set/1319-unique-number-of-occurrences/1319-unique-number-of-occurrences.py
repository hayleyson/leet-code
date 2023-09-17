from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        countDic={}
        for i in arr:
            if i in countDic:
                countDic[i]+=1
            else:
                countDic[i]=1
        return len(countDic.values())==len(set(countDic.values()))
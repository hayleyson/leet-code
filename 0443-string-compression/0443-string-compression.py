class Solution:

    def compress(self, chars: List[str]) -> int:

        tmp = ''
        tmp_count = 0
        i = 0
        while i < len(chars):
            if tmp != chars[i]:
                if (tmp != '') and (tmp_count > 1):
                    j = i-tmp_count+1
                    for digit in list(str(tmp_count)):
                        chars[j] = digit
                        j += 1
                    chars[j:]=chars[i:]
                    i = j
                tmp = chars[i]
                tmp_count=1
            else:
                tmp_count+=1
            i += 1
        if (tmp != '') and (tmp_count > 1):
            j = i-tmp_count+1
            for digit in list(str(tmp_count)):
                chars[j] = digit
                j += 1
            chars[j:]=chars[i:]
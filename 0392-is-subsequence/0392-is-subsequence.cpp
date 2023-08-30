class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.size() == 0) return true;
        int j = 0;
        for (const char& ch: t){
            if (s[j] == ch){
                if (++j == s.size()) return true;
            }
        }
        return false;
    }
};
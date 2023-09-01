class Solution {
public:

    bool checkVowel(char ch){
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i=0; i<k; i++){
            if (checkVowel(s[i])) count+=1;
        }
        int max_count = count;
        if (s.size()==k || max_count==k) return max_count;

        for (int i=k; i<s.size();i++){
            if (checkVowel(s[i-k])) count--;
            if (checkVowel(s[i])) count++;
            max_count = max_count > count? max_count: count;
            if (max_count==k) return max_count;
        }
        return max_count;
        
    }
};

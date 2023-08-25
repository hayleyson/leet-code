class Solution {
public:

    bool isVowel(char ch){
        ch = tolower(ch);
        if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')) return true;
        else return false;
    }

    string reverseVowels(string s) {
        vector<int> indices;
        for (int i=0; i<s.length();i++){
            char ch=s[i];
            if(isVowel(ch)){
                indices.push_back(i);
            }
        }
        for(int i=0;i<indices.size()/2;i++){
            char tmp=s[indices[i]];
            swap(s[indices[i]], s[indices[indices.size()-i-1]]);
        }
        return s;
    }
};
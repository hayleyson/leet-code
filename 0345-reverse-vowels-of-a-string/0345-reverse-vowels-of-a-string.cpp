class Solution {
public:
    string reverseVowels(string s) {
        vector<int> indices;
        for (int i=0; i<s.length();i++){
            char ch=s[i];
            if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')||(ch=='A')||(ch=='E')||(ch=='I')||(ch=='O')||(ch=='U')){
                indices.push_back(i);
            }
        }
        for(int i=0;i<indices.size()/2;i++){
            char tmp=s[indices[i]];
            // s[indices[i]]=s[indices[indices.size()-i-1]];
            // s[indices[indices.size()-i-1]]=tmp;
            swap(s[indices[i]], s[indices[indices.size()-i-1]]);
        }
        return s;
    }
};
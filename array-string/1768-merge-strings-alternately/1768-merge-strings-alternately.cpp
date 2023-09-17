class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        // std::string res ("");
        // int i = 0, j = 0;
        // while (i < word1.length()){
        //     res = res + word1[i];
        //     i ++;
        //     while (j < word2.length()){
        //         res = res + word2[j];
        //         j ++;
        //         break;
        //     }
        // }
        // if (j < word2.length()){
        //     res = res + word2.substr(j, word2.length());
        // }
        // return res;

        for (int i = 0; i < word2.length(); i++){
            word1.insert(2*i+1 > word1.length()? word1.length():2*i+1, word2, i, 1);
        }
        
        return word1;

    }
};
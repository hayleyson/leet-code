#include <stack>
#include <sstream>

class Solution {
public:
    string reverseWords(string s) {

        /* answer taken from leetcode */
        // Reverse string 
        reverse(s.begin(), s.end());
        //elpmaxe   doog a
        // Reverse every word
        int i = 0, j = 0;
        while(i != s.size()){
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
            while(i < s.size() && s[i] == ' ') i++, j++;
        } //example   good a
        // Remove extra ' '. If extra space, bring next non-space character to the front.
        i = 0, j = 0;
        while(j < s.size()){
            bool new_word = false;
            while(j < s.size() && s[j] == ' '){
                new_word = true;
                j++;
            }
            if(j == s.size()) break;
            if(new_word && i > 0) s[i++] = ' ';
            s[i++] = s[j++];
        }
        // example   good a
        // example g good a
        // example gogood a
        // example gooood a
        // example goodod a
        // example good a a
        s = s.substr(0, i);
        return s;

        /* my initial solution using sstream 
        string word, outstring="";
        stringstream ss(s);
        ss >> outstring;
        while (ss >> word){
            outstring= word + " " + outstring;
        }
        return outstring;
        */
    }
};
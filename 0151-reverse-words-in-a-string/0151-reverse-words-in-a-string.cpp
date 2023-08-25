#include <stack>
#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        std::stack<string> wordstack;
        string word;
        string outstring="";
        stringstream ss(s);
        while (ss >> word){
            wordstack.push(word);
        }

        outstring=outstring+wordstack.top();
        wordstack.pop();
        while(wordstack.empty()==false){

            outstring=outstring+" "+wordstack.top();
            wordstack.pop();
        }
        return outstring;
    }
};
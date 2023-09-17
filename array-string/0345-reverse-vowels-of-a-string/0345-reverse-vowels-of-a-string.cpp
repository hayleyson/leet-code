#include <string>
#include <cctype> // tolower
#include <utility> // swap c++11
using namespace std;

class Solution {
public:

    bool isVowel(char ch){
        ch = std::tolower(ch);
        if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')) return true;
        else return false;
    }

    string reverseVowels(string s) {
        /*two pointers solution*/
        int firstp=0, secondp=s.length()-1;

        while(firstp<secondp){
            bool firstV=isVowel(s[firstp]);
            bool secondV=isVowel(s[secondp]);
            if (firstV && secondV){
                std::swap(s[firstp], s[secondp]);
                firstp++;
                secondp--;
            } else if (firstV && ~secondV){
                secondp--;
            } else{
                firstp++;
            }
        }

        /* original solution of mine
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
        */
        return s;
    }
};
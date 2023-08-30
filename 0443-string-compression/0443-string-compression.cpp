class Solution {
public:

    void compressHelp(int& i, const int& tmp_cnt, vector<char>& chars){
        int j = i - tmp_cnt + 1;
        std::string tmp_cnt_d = to_string(tmp_cnt);
        for (const char& digit: tmp_cnt_d){
            chars[j] = digit;
            j++;
        }
        
        if (i!=j) {
            chars.erase(chars.begin()+j, chars.begin()+i);
        }
        i = j;
    }

    int compress(vector<char>& chars) {
        char tmp=' ';
        int tmp_cnt = 0;
        int i = 0, j = 0;
        while(i < chars.size()){
            if (tmp != chars[i]){
                if (tmp != ' ' && tmp_cnt > 1) compressHelp(i, tmp_cnt, chars);
                tmp = chars[i];
                tmp_cnt = 1;
            } else {
                tmp_cnt++;
            }
            i++;
        }
        if (tmp != ' ' && tmp_cnt > 1) compressHelp(i, tmp_cnt, chars);

        return chars.size();
    }
};
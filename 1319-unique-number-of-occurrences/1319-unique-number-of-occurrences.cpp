class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> intCount;
        for(const int& i: arr){
            intCount[i]++;
        }
        std::unordered_set<int> counts;
        for (auto elem: intCount){
            if(counts.find(elem.second)!=counts.end()) return false;
            counts.insert(elem.second);
        }
        return true;

        /* c.f. solution by adipycoder */
        // unordered_map<int,int> mp;
        // set<int> s;
        // for(auto p : arr){
        //     mp[p]++;
        // }
        // for(auto pr : mp){
        //     s.insert(pr.second);
        // }
        // return mp.size()==s.size();
    }
};
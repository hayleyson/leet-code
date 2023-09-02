class Solution {
public:
    // bool uniqueOccurrences(vector<int>& arr) {
    //     std::unordered_map<int, int> intCount;
    //     for(const int& i: arr){
    //         intCount[i]++;
    //     }
    //     std::unordered_map<int, int> countCount;
    //     for (auto elem: intCount){
    //         if(countCount.count(elem.second)!=0) return false;
    //         countCount[elem.second]++;
    //     }
    //     return true;
    // }

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(auto p : arr){
            mp[p]++;
        }
        for(auto pr : mp){
            s.insert(pr.second);
        }
        return mp.size()==s.size();
    }
};
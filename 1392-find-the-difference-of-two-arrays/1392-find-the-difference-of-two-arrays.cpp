class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1, s2;
        vector<int> v1, v2;

        for(const int& n: nums1){
            s1.insert(n);
        }
        for(const int& m: nums2){
            s2.insert(m);
        }
        for(const int& n: s1){
            if(s2.find(n)==s2.end()) v1.push_back(n);
        }
        for(const int& m: s2){
            if(s1.find(m)==s1.end()) v2.push_back(m);
        }

        return vector<vector<int>>{v1, v2};

    }
};
